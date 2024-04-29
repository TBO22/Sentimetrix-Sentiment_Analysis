#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <msclr/marshal_cppstd.h>
namespace SentimetrixForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace std;

	struct Adjective {
		string word;
		int score;
	};

	struct Modifier {
		string word;
		int score;
		bool negator = false;
	};
	vector<Modifier> m_modifiers;
	vector<Adjective> m_adjectives;
	public ref class Analyzing : public System::Windows::Forms::Form
	{
	public:

		Analyzing()
		{
			InitializeComponent();
			InitializeBackend();
			button3->Click += gcnew System::EventHandler(this, &Analyzing::button3_Click); 
			System::Drawing::Drawing2D::GraphicsPath^ roundedRectangle = gcnew System::Drawing::Drawing2D::GraphicsPath();
			roundedRectangle->AddArc(0, 0, 30, 30, 180, 90);
			roundedRectangle->AddArc(this->button3->Width - 30, 0, 30, 30, 270, 90);
			roundedRectangle->AddArc(this->button3->Width - 30, this->button3->Height - 30, 30, 30, 0, 90);
			roundedRectangle->AddArc(0, this->button3->Height - 30, 30, 30, 90, 90);
			roundedRectangle->CloseAllFigures();

			// Apply the rounded rectangle as the region of the button to get rounded edges
			this->button3->Region = gcnew System::Drawing::Region(roundedRectangle);

			// Set FlatStyle to Flat and maintain a border
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->FlatAppearance->BorderSize = 0; // Change the border size as needed
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Black; // Change border color as needed

			resultLabel = gcnew System::Windows::Forms::Label();
			resultLabel->AutoSize = true;
			resultLabel->Location = System::Drawing::Point(490, 45); // Adjust the position as needed
			resultLabel->Font = gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->Controls->Add(resultLabel);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Analyzing()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ resultLabel;
		   void loadfile( vector<Modifier>& m_modifiers, vector<Adjective>& m_adjectives) {
			   ifstream mod("Modifiers.txt");
			   ifstream adj("Adjectives.txt");
			   string line;
			   if (!mod.is_open() && !adj.is_open()) {
				   MessageBox::Show("Error opening files!");
				   return;
			   }
			   while (getline(mod, line)) {
				   istringstream iss(line);
				   string word;
				   int score;
				   bool negator;
				   if (iss >> word >> score >> negator) {
					   Modifier temp;
					   temp.word = word;
					   temp.score = score;
					   temp.negator = negator;
					   m_modifiers.push_back(temp);
				   }
				   else {
					   cout<<"Error reading Modifiers.txt!";
				   }
			   }
			   while (getline(adj, line)) {
				   istringstream iss(line);
				   string word;
				   int score;
				   if (iss >> word >> score) {
					   Adjective temp;
					   temp.word = word;
					   temp.score = score;
					   m_adjectives.push_back(temp);
				   }
				   else {
					   MessageBox::Show("Error reading Adjectives.txt!");
				   }
			   }
		   }
		   void InitializeBackend() {
			   loadfile(m_modifiers, m_adjectives);
		   }
		   vector<string> complexSentencetoSimple(string complexSentence) {
			   vector<char> punctuation = { '.', ',', '?', ':', ';', ',', '\'', '"' };
			   string line = "";
			   vector<string> output_sentences;
			   for (char ch : complexSentence) {
				   if (find(punctuation.begin(), punctuation.end(), ch) != punctuation.end()) {
					   output_sentences.push_back(line);
					   line = "";
					   continue;
				   }
				   line += ch;
			   }
			   return output_sentences;
		   }

		   vector<string> sentenceToWords(string simpleSentence) {
			   string word = "";
			   vector<string> output_word;
			   for (char ch : simpleSentence) {
				   if (ch == ' ') {
					   output_word.push_back(word);
					   word = "";
					   continue;
				   }
				   word += ch;
			   }
			   return output_word;
		   }

		   bool isModifier(const string& word, const vector<Modifier>& m_modifiers) {
			   for (const Modifier& modifier : m_modifiers) {
				   if (word == modifier.word) {
					   return true;
				   }
			   }
			   return false;
		   }

		   bool isAdjective(const string& word, const vector<Adjective>& m_adjectives) {
			   for (const Adjective& adjective : m_adjectives) {
				   if (word == adjective.word) {
					   return true;
				   }
			   }
			   return false;
		   }

		   Modifier& findModifier(const string& modifier, vector<Modifier>& m_modifiers) {
			   for (Modifier& mod : m_modifiers) {
				   if (modifier == mod.word) {
					   return mod;
				   }
			   }
			   // Return some default value or handle this case according to your logic
			   return m_modifiers[0];
		   }

		   Adjective& findAdjective(const string& adjective, vector<Adjective>& m_adjectives) {
			   for (Adjective& adj : m_adjectives) {
				   if (adjective == adj.word) {
					   return adj;
				   }
			   }
			   // Return some default value or handle this case according to your logic
			   return m_adjectives[0];
		   }
		   int applyModifierandReturnSentiment(const vector<Modifier>& modifiers, const Adjective& adjective) {
			   int currentSentiment = adjective.score;
			   for (const Modifier& modifier : modifiers) {
				   if (modifier.negator) {
					   currentSentiment = -currentSentiment;
					   continue;
				   }
				   if (currentSentiment < 0) {
					   currentSentiment += modifier.score;
				   }
				   else if (currentSentiment > 0) {
					   currentSentiment -= modifier.score;
				   }
			   }
			   return currentSentiment;
		   }

		   int detectSentimentSimpleSentence(const string& simpleSentence, vector<Modifier>& m_modifiers, vector<Adjective>& m_adjectives) {
			   vector<string> words = sentenceToWords(simpleSentence);
			   int sentiment = 0;
			   vector<Modifier> current_modifiers;

			   for (const string& word : words) {
				   if (isModifier(word, m_modifiers)) {
					   current_modifiers.push_back(findModifier(word, m_modifiers));
				   }
				   else if (isAdjective(word, m_adjectives)) {
					   Adjective& adjective = findAdjective(word, m_adjectives);
					   int currentSentiment = applyModifierandReturnSentiment(current_modifiers, adjective);
					   sentiment += currentSentiment;
					   current_modifiers.clear();
				   }
			   }
			   return sentiment;
		   }

		   int detectSentiment(const std::string& inputSentence, vector<Modifier>& m_modifiers, vector<Adjective>& m_adjectives) {
			   vector<string> simpleSentences = complexSentencetoSimple(inputSentence);
			   int sentiment = 0;

			   for (const std::string& sentence : simpleSentences) {
				   int currentSentiment = detectSentimentSimpleSentence(sentence, m_modifiers, m_adjectives);
				   sentiment += currentSentiment;
			   }

			   return sentiment;
		   }
		   void display(String^ s)
		   {
			   resultLabel->Text = s;
		   }
		   void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			   String^ inputsentence = textBox1->Text;
			   if (System::Text::RegularExpressions::Regex::IsMatch(inputsentence, "[^a-zA-Z\\s.,?!\":;'()-]")) {
				   display("Error: Please enter \nletters and spaces.");
				   pictureBox1->Image = nullptr;
				   return; 
			   }
			   marshal_context context;
			   std::string inputSentence = context.marshal_as<std::string>(inputsentence);
			   int sentiment = detectSentiment(inputSentence, m_modifiers, m_adjectives);
			   try {
				   if (sentiment > 0) {
					   display("Sentence is positive");
					   pictureBox1->Image = Image::FromFile("happy2.png");
				   }
				   else if (sentiment < 0) {
					   display("Sentence is negative");
					   pictureBox1->Image = Image::FromFile("best angry gif.gif");
				   }
				   else {
					   display("Sentence is neutral");
					   pictureBox1->Image = Image::FromFile("neutral gif.gif");
				   }
			   }
			   catch (Exception^ ex) {
				   display("Error loading \n    image");
			   }

		   }

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Analyzing::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Elephant", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Green;
			this->label1->Location = System::Drawing::Point(35, 40);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(307, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Text To Analyze";
			this->label1->Click += gcnew System::EventHandler(this, &Analyzing::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(1) { L"Enter Text" });
			this->textBox1->BackColor = System::Drawing::Color::Turquoise;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(32, 89);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(386, 200);
			this->textBox1->TabIndex = 1;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Gold;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(312, 311);
			this->button3->Name = L"button3";
			this->button3->Padding = System::Windows::Forms::Padding(10);
			this->button3->Size = System::Drawing::Size(153, 52);
			this->button3->TabIndex = 2;
			this->button3->Text = L"SentiCheck ";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Analyzing::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Aqua;
			this->pictureBox1->Location = System::Drawing::Point(489, 98);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(186, 141);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Analyzing::pictureBox1_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Chartreuse;
			this->button6->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(597, 317);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(126, 46);
			this->button6->TabIndex = 4;
			this->button6->Text = L"Check Again";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Analyzing::button6_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(17, 321);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 40);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Analyzing::button1_Click);
			// 
			// Analyzing
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Cyan;
			this->ClientSize = System::Drawing::Size(735, 375);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::PanNW;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Analyzing";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Analyzing";
			this->Load += gcnew System::EventHandler(this, &Analyzing::Analyzing_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		resultLabel->Text = "";
		textBox1->Text = "";
		pictureBox1->Image = nullptr;
	}
	private: System::Void Analyzing_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBoxButtons buttons = MessageBoxButtons::YesNoCancel;
		System::String^ message = "Do you want to exit the application?\n Press Yes to Exit.\n Press Cancel to go back to Start Page.";
		System::String^ caption = "Confirmation";
		System::Windows::Forms::DialogResult result;

		// Display the custom dialog
		result = MessageBox::Show(this, message, caption, buttons, MessageBoxIcon::Question);

		// Process the user's choice
		if (result == System::Windows::Forms::DialogResult::Yes) {
			// Close the entire application
			Application::Exit();
		}
		else if (result == System::Windows::Forms::DialogResult::No) {
			this->Show();
		}
		else if (result == System::Windows::Forms::DialogResult::Cancel) {
			this->Close();
			resultLabel->Text = "";
			textBox1->Text = "";
			pictureBox1->Image = nullptr;

		}
	}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
}