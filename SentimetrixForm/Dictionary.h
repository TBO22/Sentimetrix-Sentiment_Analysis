#pragma once
#include<regex>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <iostream>
#include <string>
#include<sstream>
#include <Windows.h>

namespace SentimetrixForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Dictionary
	/// </summary>
	public ref class Dictionary : public System::Windows::Forms::Form
	{
	public:
		Dictionary(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Dictionary()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
		   bool wordExists(const std::string& filePath, const std::string& word) {
			   std::ifstream file(filePath);
			   std::string line;
			   while (std::getline(file, line)) {
				   std::istringstream iss(line);
				   std::string existingWord;
				   iss >> existingWord;
				   if (existingWord == word) {
					   file.close();
					   return true;
				   }
			   }
			   file.close();
			   return false;
		   }
		   bool modifierExists(const std::string& filePath, const std::string& word) {
			   std::ifstream file(filePath);
			   std::string line;
			   while (std::getline(file, line)) {
				   std::istringstream iss(line);
				   std::string existingWord;
				   iss >> existingWord;
				   if (existingWord == word) {
					   file.close();
					   return true;
				   }
			   }
			   file.close();
			   return false;
		   }


	protected:

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dictionary::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(230, 153);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(186, 35);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Dictionary::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(297, 206);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(33, 33);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Dictionary::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(588, 206);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(32, 33);
			this->textBox3->TabIndex = 3;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Dictionary::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(507, 153);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(186, 35);
			this->textBox4->TabIndex = 2;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Dictionary::textBox4_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Aqua;
			this->label1->Font = (gcnew System::Drawing::Font(L"Elephant", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label1->Location = System::Drawing::Point(193, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(223, 35);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Add Adjectives";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Elephant", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label2->Location = System::Drawing::Point(472, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(221, 35);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Add Modifiers";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Elephant", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Crimson;
			this->label3->Location = System::Drawing::Point(12, 153);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(215, 35);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Enter Words : ";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->button1->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(609, 325);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 38);
			this->button1->TabIndex = 7;
			this->button1->Text = L"SentiBoost";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Dictionary::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Elephant", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(13, 206);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(254, 100);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Enter Sentiment Value ->\r\nPositive Sentiment : 1\r\nNegative Sentiment : -1\r\nNeutra"
				L"l Sentiment : 0\r\n";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Red;
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button2->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(12, 325);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(114, 38);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Dictionary::button2_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(588, 256);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(31, 33);
			this->textBox5->TabIndex = 10;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &Dictionary::textBox5_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Elephant", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(404, 256);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(173, 75);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Negator Value ->\r\nTrue : 1\r\nFalse : 0";
			// 
			// Dictionary
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Aqua;
			this->ClientSize = System::Drawing::Size(735, 375);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Cursor = System::Windows::Forms::Cursors::PanNW;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Dictionary";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dictionary";
			this->Load += gcnew System::EventHandler(this, &Dictionary::Dictionary_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		// Method to hide specific controls (label and textbox) on Form2
	public:
		// Method to hide specific controls on Form2 based on the button clicked in Form1
		void HideLabelAndTextbox(bool hideForModifier, bool hideForAdjective) {
			label1->Visible = !hideForModifier;
			textBox1->Visible = !hideForModifier;
			textBox2->Visible = !hideForModifier;

			// For Modifiers button click
			label2->Visible = !hideForAdjective;
			label5->Visible = !hideForAdjective;
			textBox3->Visible = !hideForAdjective;
			textBox4->Visible = !hideForAdjective;
			textBox5->Visible = !hideForAdjective;
		}
	private: System::Void contextMenuStrip2_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		textBox1->Text = "";
		textBox2->Text = "";
		textBox3->Text = "";
		textBox4->Text = "";
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ wordAdjective = textBox1->Text;
		String^ sentimentValueAdjective = textBox2->Text;

		if (textBox1->Visible && textBox2->Visible) {
			if (String::IsNullOrEmpty(wordAdjective) || String::IsNullOrEmpty(sentimentValueAdjective)) {
				MessageBox::Show("Please enter both word, sentiment value, and negator value for modifiers!");
			}
			else {
				std::regex wordRegex("^[a-zA-Z]+$");
				std::string wordStd = msclr::interop::marshal_as<std::string>(wordAdjective);
				bool isWordAdjective = std::regex_match(wordStd, wordRegex);

				int valueAdjective;
				bool isValidSentimentAdjective = Int32::TryParse(sentimentValueAdjective, valueAdjective);

				if (isWordAdjective && isValidSentimentAdjective && (valueAdjective == 0 || valueAdjective == -1 || valueAdjective == 1)) {
					std::string filePath = "Adjectives.txt";

					if (!wordExists(filePath, wordStd)) {
	
						try {
							std::ofstream sw(filePath, std::ios_base::app);
							if (!sw.is_open()) {
								throw std::runtime_error("Unable to open file for writing.");
							}

							sw << msclr::interop::marshal_as<std::string>(wordAdjective) << " " << msclr::interop::marshal_as<std::string>(sentimentValueAdjective) << std::endl;
							sw.close();

							textBox1->Clear();
							textBox2->Clear();

							MessageBox::Show("Data written to file successfully!");
						}
						catch (const std::exception& ex) {
							MessageBox::Show("Error writing to file: " + gcnew System::String(ex.what()));
						}

					}
					else {
						MessageBox::Show("Word already exists in the file!");
					}
				}
				else {
					if (!isWordAdjective) {
						MessageBox::Show("Please enter a valid word (only letters) in Text Box!");
					}
					else {
						MessageBox::Show("Please enter a valid sentiment value (0, -1, or 1) in Text Box!");
					}
				}
			}
		}

		// Modifiers Validation
		String^ wordModifier = textBox4->Text;
		String^ sentimentValueModifier = textBox3->Text;
		String^ negatorValue = textBox5->Text;

		if (textBox4->Visible && textBox3->Visible && textBox5->Visible) {
			if (String::IsNullOrEmpty(wordModifier) || String::IsNullOrEmpty(sentimentValueModifier) || String::IsNullOrEmpty(negatorValue)) {
				MessageBox::Show("Please enter both word, sentiment value, and negator value for modifiers!");
			}
			else {
				std::regex wordRegexModifier("^[a-zA-Z]+$");
				std::string wordStdModifier = msclr::interop::marshal_as<std::string>(wordModifier);
				bool isWordModifier = std::regex_match(wordStdModifier, wordRegexModifier);

				int parsedNegator;
				bool isValidNegator = Int32::TryParse(negatorValue, parsedNegator);

				if (isWordModifier && isValidNegator) {
					int valueModifier;
					bool isValidSentimentModifier = Int32::TryParse(sentimentValueModifier, valueModifier);

					if (isValidSentimentModifier && (valueModifier == 0 || valueModifier >= -3 || valueModifier >= 3)) {
						try {
							String^ modifierFilePath = "Modifiers.txt";

							if (!modifierExists(msclr::interop::marshal_as<std::string>(modifierFilePath), wordStdModifier)) {
								System::IO::StreamWriter^ modifierSW = gcnew System::IO::StreamWriter(modifierFilePath, true);
								modifierSW->WriteLine(wordModifier + " " + sentimentValueModifier + " " + negatorValue);
								modifierSW->Close();

								textBox4->Clear();
								textBox3->Clear();
								textBox5->Clear();

								MessageBox::Show("Data written to modifiers file successfully!");
							}
							else {
								MessageBox::Show("Word already exists in the modifiers file!");
							}
						}
						catch (Exception^ ex) {
							MessageBox::Show("Error writing to modifiers file: " + ex->Message);
						}
					}
					else {
						MessageBox::Show("Please enter a valid sentiment value (-1, 0, or 1) for modifiers!");
					}
				}
				else {
					if (!isWordModifier) {
						MessageBox::Show("Please enter a valid word (only letters) for modifiers!");
					}
					else {
						MessageBox::Show("Please enter a valid negator value (0 or 1) for modifiers!");
					}
				}
			}
		}
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Dictionary_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}

