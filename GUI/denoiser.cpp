#include <iostream>
#include <opencv2/opencv.hpp>
#include <optix_world.h>

#include "utilities.h"
#include "denoiser.h"

using namespace cv;
using namespace std;

optix::Context optix_context;
optix::Buffer input_buffer;
optix::Buffer output_buffer;
optix::Buffer albedo_buffer;
optix::Buffer normal_buffer;
optix::PostprocessingStage denoiserStage;
optix::CommandList commandList;

void createContext(const int width, const int height, const float blend, const unsigned hdr)
{
	optix_context = optix::Context::create();
	input_buffer = optix_context->createBuffer(RT_BUFFER_INPUT, RT_FORMAT_FLOAT4, width, height);
	output_buffer = optix_context->createBuffer(RT_BUFFER_OUTPUT, RT_FORMAT_FLOAT4, width, height);
	albedo_buffer = optix_context->createBuffer(RT_BUFFER_INPUT, RT_FORMAT_FLOAT4, width, height);
	normal_buffer = optix_context->createBuffer(RT_BUFFER_INPUT, RT_FORMAT_FLOAT4, width, height);
	denoiserStage = optix_context->createBuiltinPostProcessingStage("DLDenoiser");

	denoiserStage->declareVariable("input_buffer")->set(input_buffer);
	denoiserStage->declareVariable("output_buffer")->set(output_buffer);
	denoiserStage->declareVariable("input_normal_buffer")->set(normal_buffer);
	denoiserStage->declareVariable("input_albedo_buffer")->set(albedo_buffer);

	denoiserStage->declareVariable("blend")->setFloat(blend);
	denoiserStage->declareVariable("hdr")->setUint(hdr);
	
	commandList = optix_context->createCommandList();
	// Add the denoiser to the new optix command list	
	commandList->appendPostprocessingStage(denoiserStage, width, height);
	commandList->finalize();
	// Compile context. I'm not sure if this is needed given there is no megakernal?
	optix_context->validate();
	optix_context->compile();

}

#define DESTROY(X) if (X) { X->destroy(); }

void destroy()
{
	DESTROY(denoiserStage);
	DESTROY(commandList);
	DESTROY(input_buffer);
	DESTROY(output_buffer);
	DESTROY(normal_buffer);
	DESTROY(albedo_buffer);
	DESTROY(optix_context);
}

Mat denoise_impl(const Mat & beauty, const bool useAlbedo, const cv::Mat & albedo, const bool useNormal, const Mat & normal, const float blend, const unsigned hdr, const bool rebuild)
{
	int width, height;

	Mat output = beauty.clone();

	width = beauty.cols;
	height = beauty.rows;
	
	if (rebuild)
	{
		destroy();
		createContext(width, height, blend, hdr);
	}

	uchar *buffer = (uchar*)input_buffer->map();

	for (int i = 0; i < height; ++i)
	{
		memcpy(buffer + sizeof(float) * 4 * width * i, beauty.ptr<Vec4f>(i), sizeof(float) * 4 * width);
	}
	input_buffer->unmap();
	

	if (useAlbedo)
	{
		
		buffer = (uchar*)albedo_buffer->map();
		for (int i = 0; i < height; ++i)
		{
			memcpy(buffer + sizeof(float) * 4 * width * i, albedo.ptr<Vec4f>(i), sizeof(float) * 4 * width);
		}
		albedo_buffer->unmap();
		
	}
	
	if (useNormal)
	{
		
		buffer = (uchar*)normal_buffer->map();
		for (int i = 0; i < height; ++i)
		{
			memcpy(buffer + sizeof(float) * 4 * width * i, normal.ptr<Vec4f>(i), sizeof(float) * 4 * width);
		}
		normal_buffer->unmap();
		
	}
	

	// Setup the optix denoiser post processing stage	
	
	

	// Execute denoise
	std::cout << "Denoising..." << std::endl;
	commandList->execute();
	std::cout << "Denoising complete" << std::endl;

	buffer = (uchar*)output_buffer->map();

	for (int i = 0; i < height; ++i)
	{
		memcpy(output.ptr<Vec4f>(i), buffer + sizeof(float) * 4 * width * i, sizeof(float) * 4 * width);
	}
	output_buffer->unmap();

	

	return output;
}