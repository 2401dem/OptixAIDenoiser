#pragma once

namespace GUI 
{
	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;
	cv::Mat imageBox = cv::Mat(cv::Size(720, 720), CV_8UC3);


	/// <summary>
	/// MainForm 摘要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		String ^beautyPath = "test.png";
		String ^albedoPath = "albedo.png";
		String ^normalPath = "normal.png";
		String ^savePath = "out.png";
		unsigned int useHDR = 0;
		float blend = 0.05;
		bool useAlbedo = 0;
		bool useNormal = 0;

	private: array<TextBox^>^ textBoxes;
	private: array<String^>^ paths;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckBox^  checkBox3;	
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;


	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	public:	

		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//

			textBoxes = gcnew array<TextBox^>{textBox1, textBox2, textBox3, textBox4};
			paths = gcnew array<String^>{ "test.png" , "albedo.png" , "normal.png", "test_out.png" };
			cv::namedWindow("view", cv::WINDOW_AUTOSIZE);
			HWND hCV = HWND(cvGetWindowHandle("view"));
			HWND hParent = ::GetParent(hCV);
			SetParent(hCV, (HWND)(void*)(panel1->Handle));
			ShowWindow(hParent, SW_HIDE);	
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->AutoScrollMinSize = System::Drawing::Size(720, 720);
			this->panel1->Location = System::Drawing::Point(304, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(720, 720);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(40, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Input Texture";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(42, 61);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(142, 21);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(190, 60);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"open";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(24, 102);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(108, 16);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"Albedo Texture";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox1_CheckedChanged);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(190, 123);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"open";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(42, 124);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(142, 21);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox2_TextChanged);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(190, 186);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 9;
			this->button3->Text = L"open";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(42, 187);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(142, 21);
			this->textBox3->TabIndex = 8;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox3_TextChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(24, 165);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(108, 16);
			this->checkBox2->TabIndex = 7;
			this->checkBox2->Text = L"Normal Texture";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox2_CheckedChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(190, 256);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 12;
			this->button4->Text = L"open";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(42, 257);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(142, 21);
			this->textBox4->TabIndex = 11;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox4_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 242);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 12);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Output Texture";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(100, 314);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(84, 16);
			this->checkBox3->TabIndex = 13;
			this->checkBox3->Text = L"Batch Mode";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox3_CheckedChanged);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(24, 727);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(1000, 41);
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 14;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(24, 381);
			this->trackBar1->Maximum = 20;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(241, 45);
			this->trackBar1->TabIndex = 15;
			this->trackBar1->Value = 1;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MainForm::trackBar1_Scroll);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->numericUpDown1->DecimalPlaces = 2;
			this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 131072 });
			this->numericUpDown1->Location = System::Drawing::Point(190, 354);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(75, 21);
			this->numericUpDown1->TabIndex = 16;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 131072 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericUpDown1_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(143, 359);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 12);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Blend";
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(100, 433);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(72, 16);
			this->checkBox4->TabIndex = 18;
			this->checkBox4->Text = L"HDR Mode";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox4_CheckedChanged);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(42, 497);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(223, 71);
			this->button5->TabIndex = 19;
			this->button5->Text = L"Denoise";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			this->button5->MouseEnter += gcnew System::EventHandler(this, &MainForm::button5_MouseEnter);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(42, 595);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(223, 48);
			this->button6->TabIndex = 20;
			this->button6->Text = L"Open Result";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"Image Files|*.bmp;*.png;*.tif;*.jpg;*.exr|All Files|*.*";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::openFileDialog1_FileOk);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"Image Files|*.bmp;*.png;*.tif;*.jpg;*.exr|All Files|*.*";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1036, 780);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Denoiser";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//delegate void changeText
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		readFile(0);
		if (!isBatchMode && File::Exists(paths[0]))
		{
			textBox4->Text = savePath = Path::GetDirectoryName(paths[0]) + "\\" + Path::GetFileNameWithoutExtension(paths[0]) + "_out" + Path::GetExtension(paths[0]);
		}
	}

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		paths[0] = textBox1->Text;
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		readFile(1);
	}

	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		paths[1] = textBox2->Text;
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		readFile(2);
	}

	private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		paths[2] = textBox3->Text;
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		saveFile();
	}

	private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		paths[3] = textBox4->Text;
	}

	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		textBox2->Enabled = checkBox1->Checked;
		button2->Enabled = checkBox1->Checked;
		useAlbedo = checkBox1->Checked;
	}

	private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		textBox3->Enabled = checkBox2->Checked;
		button3->Enabled = checkBox2->Checked;
		useNormal = checkBox2->Checked;
	}
	
			 bool isDenoising;
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		button5->Text = "Denoising...";

		Task^ task = Task::Factory->StartNew(gcnew Action(this, &MainForm::denoiseFile));		
		
	}
			 delegate void DlgChangeText(String^ str);
	private: void changeText(String^ str)
	{
		button5->Text = str;
		isDenoising = 0;
	}
	
			 delegate void DlgSetProgressBar(float pct);
	private: void setProgressBar(float pct)
	{
		progressBar1->Value = pct * 100;
	}

			 Int32 lastH = -1;
			 Int32 lastW = -1;
	private: void denoiseFile()
	{		
		this->Invoke(gcnew DlgSetProgressBar(this, &MainForm::setProgressBar), gcnew array<System::Object^>{ 0 });
		if (isBatchMode)
		{
			if (!batchModeDenoise())
			{
				this->Invoke(gcnew DlgChangeText(this, &MainForm::changeText), gcnew array<System::Object^>{"Done"});
			}
			else
			{
				this->Invoke(gcnew DlgChangeText(this, &MainForm::changeText), gcnew array<System::Object^>{"Error"});
			}			
		}
		else
		{
			beautyPath = paths[0];
			albedoPath = paths[1];
			normalPath = paths[2];
			savePath = paths[3];
			isDenoising = 1;
			lastH = lastW = -1;

			
			if (!denoise(beautyPath, albedoPath, normalPath, savePath))
			{
				this->Invoke(gcnew DlgChangeText(this, &MainForm::changeText), gcnew array<System::Object^>{"Done"});
			}
			else
			{
				this->Invoke(gcnew DlgChangeText(this, &MainForm::changeText), gcnew array<System::Object^>{"Error"});
			}
			this->Invoke(gcnew DlgSetProgressBar(this, &MainForm::setProgressBar), gcnew array<System::Object^>{ 1.0f });
		}
		
	}
	
	private: bool batchModeDenoise()
	{
		if (!Directory::Exists(paths[0]))
		{
			MessageBox::Show("Input folder does not exists.", "Error", MessageBoxButtons::OK);
			Console::WriteLine("Error: Input folder does not exists.");

			return -1;
		}
		clock_t start, end;
		start = clock();
		DirectoryInfo^ info = gcnew DirectoryInfo(paths[0]);
		Int32 len = info->GetFiles()->GetLength(0);

		array<String^>^ inputFiles = gcnew array<String^>(len);
		array<String^>^ albedoFiles = gcnew array<String^>(len);
		array<String^>^ normalFiles = gcnew array<String^>(len);
		array<String^>^ outFiles = gcnew array<String^>(len);

		Int32 cnt0 = 0;
		for each (auto file in info->GetFiles())
		{
			String^ ext = Path::GetExtension(file->Name);
			if (ext == ".png" || ext == ".bmp" || ext == ".exr" || ext == ".tif" || ext == ".jpg")
			{
				//Console::WriteLine(file->Name);
				inputFiles[cnt0] = (paths[0] + "\\" + file->Name);
				outFiles[cnt0] = (paths[3] + "\\" + Path::GetFileNameWithoutExtension(file->Name) + "_out" + Path::GetExtension(file->Name));
				cnt0++;
			}
		}
		Console::WriteLine("Total: ", cnt0.ToString());

		Int32 cnt1 = 0;
		if (useAlbedo)
		{
			if (!Directory::Exists(paths[1]))
			{
				MessageBox::Show("The albedo folder does not exists.", "Error", MessageBoxButtons::OK);
				Console::WriteLine("Error: The albedo folder does not exists.");

				return -1;
			}
			info = gcnew DirectoryInfo(paths[1]);
			for each (auto file in info->GetFiles())
			{

				String^ ext = Path::GetExtension(file->Name);
				if (ext == ".png" || ext == ".bmp" || ext == ".exr" || ext == ".tif" || ext == ".jpg")
				{
					//Console::WriteLine(file->Name);
					albedoFiles[cnt1] = (paths[1] + "\\" + file->Name);
					cnt1++;
				}
			}
			if (cnt1 != cnt0)
			{
				MessageBox::Show("The number of files in the albedo folder does not match." , "Error", MessageBoxButtons::OK);
				Console::WriteLine("Error: The number of files in the albedo folder does not match.");

				return -1;
			}
		}

		Int32 cnt2 = 0;
		if (useNormal)
		{
			if (!Directory::Exists(paths[2]))
			{
				MessageBox::Show("The normal folder does not exists.", "Error", MessageBoxButtons::OK);
				Console::WriteLine("Error: The normal folder does not exists.");

				return -1;
			}
			info = gcnew DirectoryInfo(paths[2]);
			for each (auto file in info->GetFiles())
			{

				String^ ext = Path::GetExtension(file->Name);
				if (ext == ".png" || ext == ".bmp" || ext == ".exr" || ext == ".tif" || ext == ".jpg")
				{
					//Console::WriteLine(file->Name);
					normalFiles[cnt2] = (paths[2] + "\\" + file->Name);
					cnt2++;
				}
			}
			if (cnt2 != cnt0)
			{
				MessageBox::Show("The number of files in the normal folder does not match.", "Error", MessageBoxButtons::OK);
				Console::WriteLine("Error: The number of files in the normal folder does not match.");

				return -1;
			}
		}
		
		lastH = lastW = -1;
//#pragma omp parallel for
		for (int i = 0; i < cnt0; ++i)
		{
			beautyPath = inputFiles[i];
			albedoPath = albedoFiles[i];
			normalPath = normalFiles[i];
			savePath = outFiles[i];
			bool res = 0;
			res = denoise(beautyPath, albedoPath, normalPath, savePath);
			if (!res)
			{
				this->Invoke(gcnew DlgSetProgressBar(this, &MainForm::setProgressBar), gcnew array<System::Object^>{ (float)i / (float)len });
			}
			else
			{
				//return -1;
			}
			
		}
		this->Invoke(gcnew DlgSetProgressBar(this, &MainForm::setProgressBar), gcnew array<System::Object^>{ 1.0f });
		end = clock();

		std::cout << "Time Cost: " << (float)(end - start) / CLOCKS_PER_SEC << std::endl;

		return 0;
	}
	
	private: bool denoise(String^ beautyPath, String^ albedoPath, String^ normalPath, String^ savePath)
	{
		if (!File::Exists(beautyPath))
		{
			MessageBox::Show("The input texture does not exists.", "Error", MessageBoxButtons::OK);
			Console::WriteLine("Error: The input texture does not exists.");
			
			return -1;
		}
		cv::Mat bet;
		cv::Mat abd;
		cv::Mat nml;

		bet = cv::imread((char*)(void*)Marshal::StringToHGlobalAnsi(beautyPath), cv::IMREAD_UNCHANGED);
		Int32 depth = getBitDepth(bet);
		int rtype = bet.depth();

		bool rebuild = 1;
		if (bet.cols == lastW && bet.rows == lastH)
		{
			rebuild = 0;
		}
		else
		{
			lastW = bet.cols;
			lastH = bet.rows;
		}
		Console::WriteLine("depth: " + depth.ToString());
		Console::WriteLine("size: " + Int32(bet.cols).ToString() + "x" + Int32(bet.rows).ToString());

		bet.convertTo(bet, CV_32F, getAlphaTo32F(bet));
		cv::cvtColor(bet, bet, CV_BGR2RGBA);

		if (useAlbedo)
		{
			if (!File::Exists(albedoPath))
			{
				MessageBox::Show("The albedo texture does not exists.", "Error", MessageBoxButtons::OK);
				Console::WriteLine("Error: The albedo texture does not exists.");
				
				return -1;
			}
			abd = imread((char*)(void*)Marshal::StringToHGlobalAnsi(albedoPath), cv::IMREAD_UNCHANGED);
			abd.convertTo(abd, CV_32F, getAlphaTo32F(abd));
			cv::cvtColor(abd, abd, CV_BGR2RGBA);
		}
		if (useNormal)
		{
			if (!File::Exists(normalPath))
			{
				MessageBox::Show("The normal texture does not exists.", "Error", MessageBoxButtons::OK);
				Console::WriteLine("Error: The normal texture does not exists.");
				
				return -1;
			}
			nml = imread((char*)(void*)Marshal::StringToHGlobalAnsi(normalPath), cv::IMREAD_UNCHANGED);
			nml.convertTo(nml, CV_32F, getAlphaTo32F(nml));
			cv::cvtColor(nml, nml, CV_BGR2RGBA);
		}

		bet = denoise_impl(bet, useAlbedo, abd, useNormal, nml, blend, useHDR, rebuild);

		cv::cvtColor(bet, bet, CV_RGBA2BGR);

		fillImageBox(bet, imageBox);
		cv::imshow("view", imageBox);

		switch (rtype)
		{
		case CV_8U:
			bet.convertTo(bet, CV_8U, 255);
			break;
		case CV_16U:
			bet.convertTo(bet, CV_16U, 256 * 256 - 1);
			break;
		case CV_32F:
			break;
		default:
			bet.convertTo(bet, CV_8U, getAlphaTo8U(bet));
			break;
		}
		if (!cv::imwrite((char*)(void*)Marshal::StringToHGlobalAnsi(savePath), bet))
		{
			MessageBox::Show("Failed to wirte output file.", "Error", MessageBoxButtons::OK);
			Console::WriteLine("Error: Failed to wirte output file.");
			return -1;
		}
		return 0;
	}

	private: System::Void button5_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{	
		if (!isDenoising)
		{
			button5->Text = "Denoise";
		}
	}

	private: Void readFile(Int32 index)
	{	
		if (isBatchMode)
		{
			/*char buffer[128];
			BROWSEINFO bi;
			ZeroMemory(&bi, sizeof(BROWSEINFO));
			bi.hwndOwner = NULL;
			bi.ulFlags = BIF_RETURNONLYFSDIRS;
			ITEMIDLIST *pidl = SHBrowseForFolder(&bi);
			if (pidl != NULL)
			{
				SHGetPathFromIDList(pidl, buffer);
				textBoxes[index]->Text = Marshal::PtrToStringAnsi((IntPtr)(void*)buffer);
			}*/
			
			batchModeSelect(index);
		}
		else
		{
			
			openFileDialog1->FileName = textBoxes[index]->Text;
			openFileDialog1->InitialDirectory = textBoxes[index]->Text;
			auto result = openFileDialog1->ShowDialog();
			if (result == System::Windows::Forms::DialogResult::OK)
			{
				textBoxes[index]->Text = openFileDialog1->FileName;
				paths[index] = textBoxes[index]->Text;
			}
			
		}
	}

	private: Void saveFile()
	{
		if (isBatchMode)
		{
			batchModeSelect(3);
		}
		else
		{
			auto result = saveFileDialog1->ShowDialog();
			if (result == System::Windows::Forms::DialogResult::OK)
			{
				textBox4->Text = saveFileDialog1->FileName;
				savePath = textBox4->Text;
			}
		}		
	}
	
	private: void batchModeSelect(Int32 index)
	{
		IFileOpenDialog *pfd = NULL;
		HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pfd));
		DWORD dwFlags;
		hr = pfd->GetOptions(&dwFlags);
		hr = pfd->SetOptions(dwFlags | FOS_PICKFOLDERS);
		hr = pfd->Show(NULL);
		LPWSTR pszFilePath = NULL;
		IShellItem *ppsi = NULL;
		hr = pfd->GetFolder(&ppsi);
		hr = ppsi->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
		if (SUCCEEDED(hr))
		{
			textBoxes[index]->Text = Marshal::PtrToStringAuto((IntPtr)(void*)pszFilePath);
			paths[index] = textBoxes[index]->Text;
		}
		CoTaskMemFree(pszFilePath);
		//CoTaskMemFree(ppsi);
		pfd->Release();
	}

	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
	{
		//
	}

	private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		useHDR = checkBox4->Checked ? 1 : 0;
	}

	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e)
	{
		blend = (float)(trackBar1->Value) / 20;
		numericUpDown1->Value = Convert::ToDecimal(blend);
	}

	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		blend = (float)numericUpDown1->Value;
		trackBar1->Value = blend * 20;
	}

	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//if (Directory::Exists(Path::GetDirectoryName(paths[3])))
		if (File::Exists(paths[3]))
		{
			ITEMIDLIST *pidl = ILCreateFromPath((char*)(void*)Marshal::StringToHGlobalAnsi(paths[3]));
			SHOpenFolderAndSelectItems(pidl, 0, 0, 0);
			ILFree(pidl);
		}
		if (Directory::Exists(paths[3]))
		{			
			ShellExecute(NULL, NULL, (char*)(void*)Marshal::StringToHGlobalAnsi(paths[3]), NULL, NULL, SW_SHOWNORMAL);
		}
	}
			 bool isBatchMode;
	private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		isBatchMode = checkBox3->Checked;
		if (isBatchMode)
		{
			label1->Text = "Input Folder";
			checkBox1->Text = "Albedo Folder";
			checkBox2->Text = "Normal Folder";
			label2->Text = "Output Folder";
		}
		else
		{
			label1->Text = "Input Texture";
			checkBox1->Text = "Albedo Texture";
			checkBox2->Text = "Normal Texture";
			label2->Text = "Output Texture";
		}
	}
};
}
