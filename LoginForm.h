#pragma once
#include "MainForm.h"

namespace PassSaver {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		static String^ DBPath() 
		{
			return DataBasePath;
		}

		static bool IsImport()
		{
			return isImport;
		}

		static String^ Password()
		{
			return pass;
		}
		
		static void SetPassword(String^ password)
		{
			pass = password;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
		static String^ DataBasePath;
		static bool isImport;
		static String^ pass;

	private: System::Windows::Forms::Button^ buttonCreateDB;
	private: System::Windows::Forms::Button^ buttonImportDB;
	protected:


	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::TextBox^ textBoxPassword;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::Label^ labelDBLocation;



	public: System::Windows::Forms::TextBox^ textBoxDBPath;

	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ buttonSetPath;
	private: System::Windows::Forms::Button^ buttonLaunch;

	private: System::Windows::Forms::Label^ labelRepeatPassword;

	private: System::Windows::Forms::TextBox^ textBoxReapeatPassword;
	private: System::Windows::Forms::Label^ labelPasswordStatus;




	protected:

	protected:





















	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->buttonCreateDB = (gcnew System::Windows::Forms::Button());
			this->buttonImportDB = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->labelDBLocation = (gcnew System::Windows::Forms::Label());
			this->textBoxDBPath = (gcnew System::Windows::Forms::TextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->buttonSetPath = (gcnew System::Windows::Forms::Button());
			this->buttonLaunch = (gcnew System::Windows::Forms::Button());
			this->labelRepeatPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxReapeatPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelPasswordStatus = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonCreateDB
			// 
			this->buttonCreateDB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonCreateDB->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonCreateDB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonCreateDB->ForeColor = System::Drawing::SystemColors::Control;
			this->buttonCreateDB->Location = System::Drawing::Point(247, 163);
			this->buttonCreateDB->Name = L"buttonCreateDB";
			this->buttonCreateDB->Size = System::Drawing::Size(180, 56);
			this->buttonCreateDB->TabIndex = 0;
			this->buttonCreateDB->Text = L"Create DB";
			this->buttonCreateDB->UseVisualStyleBackColor = false;
			this->buttonCreateDB->Click += gcnew System::EventHandler(this, &LoginForm::buttonCreateDB_Click);
			// 
			// buttonImportDB
			// 
			this->buttonImportDB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonImportDB->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonImportDB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonImportDB->ForeColor = System::Drawing::SystemColors::Control;
			this->buttonImportDB->Location = System::Drawing::Point(442, 163);
			this->buttonImportDB->Name = L"buttonImportDB";
			this->buttonImportDB->Size = System::Drawing::Size(180, 56);
			this->buttonImportDB->TabIndex = 1;
			this->buttonImportDB->Text = L"Import DB";
			this->buttonImportDB->UseVisualStyleBackColor = false;
			this->buttonImportDB->Click += gcnew System::EventHandler(this, &LoginForm::buttonImportDB_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Cursor = System::Windows::Forms::Cursors::Default;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cloud Light", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label1->Location = System::Drawing::Point(261, 114);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(343, 43);
			this->label1->TabIndex = 2;
			this->label1->Text = L"PassManager v1.0 beta";
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(10)));
			this->textBoxPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxPassword->Enabled = false;
			this->textBoxPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->textBoxPassword->Location = System::Drawing::Point(247, 256);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(375, 21);
			this->textBoxPassword->TabIndex = 2;
			this->textBoxPassword->UseSystemPasswordChar = true;
			this->textBoxPassword->TextChanged += gcnew System::EventHandler(this, &LoginForm::textBoxPassword_TextChanged);
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->labelPassword->Location = System::Drawing::Point(243, 232);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(77, 21);
			this->labelPassword->TabIndex = 4;
			this->labelPassword->Text = L"Password";
			// 
			// labelDBLocation
			// 
			this->labelDBLocation->AutoSize = true;
			this->labelDBLocation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->labelDBLocation->Location = System::Drawing::Point(243, 360);
			this->labelDBLocation->Name = L"labelDBLocation";
			this->labelDBLocation->Size = System::Drawing::Size(137, 21);
			this->labelDBLocation->TabIndex = 6;
			this->labelDBLocation->Text = L"Database Location";
			// 
			// textBoxDBPath
			// 
			this->textBoxDBPath->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(10)));
			this->textBoxDBPath->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxDBPath->Enabled = false;
			this->textBoxDBPath->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->textBoxDBPath->Location = System::Drawing::Point(247, 384);
			this->textBoxDBPath->Name = L"textBoxDBPath";
			this->textBoxDBPath->ReadOnly = true;
			this->textBoxDBPath->Size = System::Drawing::Size(292, 21);
			this->textBoxDBPath->TabIndex = 10;
			this->textBoxDBPath->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// buttonSetPath
			// 
			this->buttonSetPath->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonSetPath->Enabled = false;
			this->buttonSetPath->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonSetPath->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSetPath->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSetPath->ForeColor = System::Drawing::SystemColors::Control;
			this->buttonSetPath->Location = System::Drawing::Point(546, 375);
			this->buttonSetPath->Margin = System::Windows::Forms::Padding(0);
			this->buttonSetPath->Name = L"buttonSetPath";
			this->buttonSetPath->Size = System::Drawing::Size(77, 30);
			this->buttonSetPath->TabIndex = 4;
			this->buttonSetPath->Text = L"Set Path";
			this->buttonSetPath->UseVisualStyleBackColor = false;
			this->buttonSetPath->Click += gcnew System::EventHandler(this, &LoginForm::buttonSetPath_Click);
			// 
			// buttonLaunch
			// 
			this->buttonLaunch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonLaunch->Enabled = false;
			this->buttonLaunch->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonLaunch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonLaunch->ForeColor = System::Drawing::SystemColors::Control;
			this->buttonLaunch->Location = System::Drawing::Point(247, 428);
			this->buttonLaunch->Name = L"buttonLaunch";
			this->buttonLaunch->Size = System::Drawing::Size(375, 56);
			this->buttonLaunch->TabIndex = 5;
			this->buttonLaunch->Text = L"Launch";
			this->buttonLaunch->UseVisualStyleBackColor = false;
			this->buttonLaunch->Click += gcnew System::EventHandler(this, &LoginForm::buttonLaunch_Click);
			// 
			// labelRepeatPassword
			// 
			this->labelRepeatPassword->AutoSize = true;
			this->labelRepeatPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->labelRepeatPassword->Location = System::Drawing::Point(243, 294);
			this->labelRepeatPassword->Name = L"labelRepeatPassword";
			this->labelRepeatPassword->Size = System::Drawing::Size(129, 21);
			this->labelRepeatPassword->TabIndex = 10;
			this->labelRepeatPassword->Text = L"Repeat Password";
			// 
			// textBoxReapeatPassword
			// 
			this->textBoxReapeatPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)));
			this->textBoxReapeatPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxReapeatPassword->Enabled = false;
			this->textBoxReapeatPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->textBoxReapeatPassword->Location = System::Drawing::Point(247, 318);
			this->textBoxReapeatPassword->Name = L"textBoxReapeatPassword";
			this->textBoxReapeatPassword->Size = System::Drawing::Size(375, 21);
			this->textBoxReapeatPassword->TabIndex = 3;
			this->textBoxReapeatPassword->UseSystemPasswordChar = true;
			// 
			// labelPasswordStatus
			// 
			this->labelPasswordStatus->AutoSize = true;
			this->labelPasswordStatus->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->labelPasswordStatus->Location = System::Drawing::Point(625, 232);
			this->labelPasswordStatus->Name = L"labelPasswordStatus";
			this->labelPasswordStatus->Size = System::Drawing::Size(0, 21);
			this->labelPasswordStatus->TabIndex = 11;
			this->labelPasswordStatus->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// LoginForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->ClientSize = System::Drawing::Size(867, 610);
			this->Controls->Add(this->labelPasswordStatus);
			this->Controls->Add(this->labelRepeatPassword);
			this->Controls->Add(this->textBoxReapeatPassword);
			this->Controls->Add(this->buttonLaunch);
			this->Controls->Add(this->buttonSetPath);
			this->Controls->Add(this->labelDBLocation);
			this->Controls->Add(this->textBoxDBPath);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonImportDB);
			this->Controls->Add(this->buttonCreateDB);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"LoginForm";
			this->Opacity = 0.99;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PassManager";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LoginForm::LoginForm_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void buttonCreateDB_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void buttonSetPath_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void buttonImportDB_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void buttonLaunch_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void LoginForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	
	private: System::Void textBoxPassword_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
