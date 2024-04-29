#pragma once
#include "Analyzing.h"
#include"about1.h"
#include"Dictionary.h"
namespace SentimetrixForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
public ref class HomePage : public System::Windows::Forms::Form {
	public:
		HomePage(void) {
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			aboutPage = gcnew about1();
			analyzingPage = gcnew Analyzing();
			dictionarypage = gcnew Dictionary();
		}
		
	protected:
		~HomePage() {
			if (components) {
				delete components;
			}
			delete aboutPage;
		}

	private:
		about1^ aboutPage;
		Analyzing^ analyzingPage;
		Dictionary^ dictionarypage;
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
		int remainingTime;  // for countdown timer
		System::Windows::Forms::Label^ lblTimer;
		System::Windows::Forms::Form^ customDialog;
	protected:
	private:
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HomePage::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->button2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(322, 237);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(123, 111);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &HomePage::tableLayoutPanel1_Paint);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Gold;
			this->button2->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(3, 58);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(115, 50);
			this->button2->TabIndex = 1;
			this->button2->Text = L"About Sentimetrix";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &HomePage::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Lime;
			this->button1->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 49);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &HomePage::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(255, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(253, 219);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Red;
			this->button4->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(12, 323);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(96, 40);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Exit ";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &HomePage::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LimeGreen;
			this->button3->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(608, 323);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(115, 40);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Senti Boost";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &HomePage::button3_Click);
			// 
			// HomePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Aqua;
			this->ClientSize = System::Drawing::Size(735, 375);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Cursor = System::Windows::Forms::Cursors::PanNW;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"HomePage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sentimetrix Home";
			this->Load += gcnew System::EventHandler(this, &HomePage::HomePage_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->analyzingPage->ShowDialog();
	}
private: System::Void button2_Click(System::Object ^ sender, System::EventArgs ^ e) {
	// Use the correct class name from about1.h
	this->aboutPage->ShowDialog();
	// Open About1 as a modal dialog
}
	
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::Application::Exit();
	}
private: System::Void HomePage_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	customDialog = gcnew System::Windows::Forms::Form();
	customDialog->Text = "Dictionary"; 
	customDialog->Icon = gcnew System::Drawing::Icon("logoicon.ico");
	

	customDialog->Size = System::Drawing::Size(250, 100);
	lblTimer = gcnew System::Windows::Forms::Label();
	lblTimer->Location = System::Drawing::Point(20, 50);
	lblTimer->AutoSize = true;
	customDialog->Controls->Add(lblTimer);

remainingTime = 3; // Define remainingTime here

	// Add a timer to update the countdown label every second
	System::Threading::Timer^ countdownTimer = gcnew System::Threading::Timer(
		gcnew System::Threading::TimerCallback(this, &HomePage::UpdateTimer), nullptr, 1000, 1000);

	// Add a timer to close the dialog after 3 seconds
	System::Threading::Timer^ closeTimer = gcnew System::Threading::Timer(
		gcnew System::Threading::TimerCallback(this, &HomePage::CloseDialog), nullptr, 3000, System::Threading::Timeout::Infinite);


	System::Windows::Forms::Label^ lblInstructions = gcnew System::Windows::Forms::Label();
	lblInstructions->Text = "Select an option :";
	lblInstructions->Location = System::Drawing::Point(20, 5);
	lblInstructions->AutoSize = true; // Adjusts label size based on text
	customDialog->Controls->Add(lblInstructions);
	// Create buttons for adjectives and modifiers
	System::Windows::Forms::Button^ btnAdjectives = gcnew System::Windows::Forms::Button();
	btnAdjectives->Text = "Adjectives";
	btnAdjectives->Click += gcnew System::EventHandler(this, &HomePage::btnAdjectives_Click);

	System::Windows::Forms::Button^ btnModifiers = gcnew System::Windows::Forms::Button();
	btnModifiers->Text = "Modifiers";
	
	btnModifiers->Click += gcnew System::EventHandler(this, &HomePage::btnModifiers_Click);

	// Set button positions and add them to the dialog
	btnAdjectives->Location = System::Drawing::Point(20, 20);
	btnModifiers->Location = System::Drawing::Point(120, 20);
	customDialog->Controls->Add(btnAdjectives);
	customDialog->Controls->Add(btnModifiers);
	customDialog->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	// Show the custom dialog as a modal dialog
	customDialog->ShowDialog();
}
	   System::Void btnAdjectives_Click(System::Object^ sender, System::EventArgs^ e) {
		   dictionarypage->HideLabelAndTextbox(false,true); // Call the method to hide specific controls on Form2
		   dictionarypage->ShowDialog();
	   }

	   System::Void btnModifiers_Click(System::Object^ sender, System::EventArgs^ e) {
		   dictionarypage->HideLabelAndTextbox(true,false);
		   this->dictionarypage->ShowDialog();
		  
	   }
	   private: void UpdateTimer(Object^ state) {
		   this->Invoke(gcnew Action(this, &HomePage::UpdateTimerLabel));
	   }

private: void UpdateTimerLabel() {
	if (remainingTime >= 0) {
		lblTimer->Text = "Time remaining: " + remainingTime-- + " seconds";
	}
	else {
		// Close the dialog when time is up
		this->CloseCustomDialog();
	}
}

private: void CloseDialog(Object^ state) {
	this->Invoke(gcnew Action(this, &HomePage::CloseCustomDialog));
}

private: void CloseCustomDialog() {
	// Close the dialog here
	// For example, assuming 'customDialog' is the dialog you want to close:
	customDialog->Close();
}
};
}
