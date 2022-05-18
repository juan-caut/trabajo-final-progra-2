#pragma once
#include"FormJuego.h"

namespace TrabajoF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormConfigurarNivel2
	/// </summary>
	public ref class FormConfigurarNivel2 : public System::Windows::Forms::Form
	{
	private:

		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown1;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown2;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown3;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown4;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown5;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown6;


		//fondo del form
		Bitmap^ bmpFondo;
	public:
		FormConfigurarNivel2(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			//buffer
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			//fondo
			bmpFondo = gcnew Bitmap("imagenes/fondo_configurarnivel2.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormConfigurarNivel2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->domainUpDown1 = (gcnew System::Windows::Forms::DomainUpDown());
			this->domainUpDown2 = (gcnew System::Windows::Forms::DomainUpDown());
			this->domainUpDown3 = (gcnew System::Windows::Forms::DomainUpDown());
			this->domainUpDown4 = (gcnew System::Windows::Forms::DomainUpDown());
			this->domainUpDown5 = (gcnew System::Windows::Forms::DomainUpDown());
			this->domainUpDown6 = (gcnew System::Windows::Forms::DomainUpDown());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::SaddleBrown;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Gold;
			this->button2->Location = System::Drawing::Point(12, 346);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 38);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Atrás";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &FormConfigurarNivel2::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SaddleBrown;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Gold;
			this->button1->Location = System::Drawing::Point(507, 346);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 38);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Continuar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FormConfigurarNivel2::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormConfigurarNivel2::timer1_Tick);
			// 
			// domainUpDown1
			// 
			this->domainUpDown1->BackColor = System::Drawing::Color::DarkRed;
			this->domainUpDown1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->domainUpDown1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->domainUpDown1->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->domainUpDown1->ForeColor = System::Drawing::SystemColors::Menu;
			this->domainUpDown1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->domainUpDown1->Items->Add(L"01");
			this->domainUpDown1->Items->Add(L"02");
			this->domainUpDown1->Items->Add(L"03");
			this->domainUpDown1->Items->Add(L"04");
			this->domainUpDown1->Items->Add(L"05");
			this->domainUpDown1->Items->Add(L"06");
			this->domainUpDown1->Items->Add(L"07");
			this->domainUpDown1->Items->Add(L"08");
			this->domainUpDown1->Items->Add(L"09");
			this->domainUpDown1->Items->Add(L"10");
			this->domainUpDown1->Location = System::Drawing::Point(279, 154);
			this->domainUpDown1->Name = L"domainUpDown1";
			this->domainUpDown1->ReadOnly = true;
			this->domainUpDown1->Size = System::Drawing::Size(45, 32);
			this->domainUpDown1->TabIndex = 10;
			this->domainUpDown1->Text = L"01";
			this->domainUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// domainUpDown2
			// 
			this->domainUpDown2->BackColor = System::Drawing::Color::DarkRed;
			this->domainUpDown2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->domainUpDown2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->domainUpDown2->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->domainUpDown2->ForeColor = System::Drawing::SystemColors::Menu;
			this->domainUpDown2->Items->Add(L"05");
			this->domainUpDown2->Items->Add(L"10");
			this->domainUpDown2->Items->Add(L"15");
			this->domainUpDown2->Items->Add(L"20");
			this->domainUpDown2->Items->Add(L"25");
			this->domainUpDown2->Items->Add(L"30");
			this->domainUpDown2->Items->Add(L"35");
			this->domainUpDown2->Items->Add(L"40");
			this->domainUpDown2->Items->Add(L"45");
			this->domainUpDown2->Items->Add(L"50");
			this->domainUpDown2->Items->Add(L"55");
			this->domainUpDown2->Items->Add(L"59");
			this->domainUpDown2->Location = System::Drawing::Point(344, 154);
			this->domainUpDown2->Name = L"domainUpDown2";
			this->domainUpDown2->ReadOnly = true;
			this->domainUpDown2->Size = System::Drawing::Size(45, 32);
			this->domainUpDown2->TabIndex = 11;
			this->domainUpDown2->Text = L"50";
			this->domainUpDown2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// domainUpDown3
			// 
			this->domainUpDown3->BackColor = System::Drawing::Color::DarkRed;
			this->domainUpDown3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->domainUpDown3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->domainUpDown3->Enabled = false;
			this->domainUpDown3->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->domainUpDown3->ForeColor = System::Drawing::SystemColors::Menu;
			this->domainUpDown3->Items->Add(L"20");
			this->domainUpDown3->Items->Add(L"25");
			this->domainUpDown3->Items->Add(L"30");
			this->domainUpDown3->Items->Add(L"35");
			this->domainUpDown3->Items->Add(L"40");
			this->domainUpDown3->Items->Add(L"45");
			this->domainUpDown3->Items->Add(L"50");
			this->domainUpDown3->Location = System::Drawing::Point(109, 237);
			this->domainUpDown3->Name = L"domainUpDown3";
			this->domainUpDown3->ReadOnly = true;
			this->domainUpDown3->Size = System::Drawing::Size(56, 32);
			this->domainUpDown3->TabIndex = 12;
			this->domainUpDown3->Text = L"100";
			this->domainUpDown3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// domainUpDown4
			// 
			this->domainUpDown4->BackColor = System::Drawing::Color::DarkRed;
			this->domainUpDown4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->domainUpDown4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->domainUpDown4->Enabled = false;
			this->domainUpDown4->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->domainUpDown4->ForeColor = System::Drawing::SystemColors::Menu;
			this->domainUpDown4->Items->Add(L"02");
			this->domainUpDown4->Items->Add(L"03");
			this->domainUpDown4->Items->Add(L"04");
			this->domainUpDown4->Items->Add(L"05");
			this->domainUpDown4->Location = System::Drawing::Point(214, 324);
			this->domainUpDown4->Name = L"domainUpDown4";
			this->domainUpDown4->ReadOnly = true;
			this->domainUpDown4->Size = System::Drawing::Size(45, 32);
			this->domainUpDown4->TabIndex = 13;
			this->domainUpDown4->Text = L"05";
			this->domainUpDown4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// domainUpDown5
			// 
			this->domainUpDown5->BackColor = System::Drawing::Color::DarkRed;
			this->domainUpDown5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->domainUpDown5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->domainUpDown5->Enabled = false;
			this->domainUpDown5->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->domainUpDown5->ForeColor = System::Drawing::SystemColors::Menu;
			this->domainUpDown5->Items->Add(L"01");
			this->domainUpDown5->Items->Add(L"02");
			this->domainUpDown5->Items->Add(L"03");
			this->domainUpDown5->Location = System::Drawing::Point(453, 237);
			this->domainUpDown5->Name = L"domainUpDown5";
			this->domainUpDown5->ReadOnly = true;
			this->domainUpDown5->Size = System::Drawing::Size(76, 32);
			this->domainUpDown5->TabIndex = 14;
			this->domainUpDown5->Text = L"Ilimited";
			this->domainUpDown5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// domainUpDown6
			// 
			this->domainUpDown6->BackColor = System::Drawing::Color::DarkRed;
			this->domainUpDown6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->domainUpDown6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->domainUpDown6->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->domainUpDown6->ForeColor = System::Drawing::SystemColors::Menu;
			this->domainUpDown6->Items->Add(L"100");
			this->domainUpDown6->Items->Add(L"200");
			this->domainUpDown6->Items->Add(L"300");
			this->domainUpDown6->Items->Add(L"400");
			this->domainUpDown6->Items->Add(L"500");
			this->domainUpDown6->Location = System::Drawing::Point(386, 324);
			this->domainUpDown6->Name = L"domainUpDown6";
			this->domainUpDown6->ReadOnly = true;
			this->domainUpDown6->Size = System::Drawing::Size(50, 32);
			this->domainUpDown6->TabIndex = 15;
			this->domainUpDown6->Text = L"200";
			this->domainUpDown6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// FormConfigurarNivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(621, 396);
			this->ControlBox = false;
			this->Controls->Add(this->domainUpDown6);
			this->Controls->Add(this->domainUpDown5);
			this->Controls->Add(this->domainUpDown4);
			this->Controls->Add(this->domainUpDown3);
			this->Controls->Add(this->domainUpDown2);
			this->Controls->Add(this->domainUpDown1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(637, 435);
			this->MinimumSize = System::Drawing::Size(637, 435);
			this->Name = L"FormConfigurarNivel2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EvadeCov-22: Configurar Nivel 2";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FormConfigurarNivel2::FormConfigurarNivel2_FormClosed);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
		this->Close();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//borrar
		buffer->Graphics->Clear(Color::WhiteSmoke);

		//dibujar
		buffer->Graphics->DrawImage(bmpFondo, 0, 0, bmpFondo->Width * 0.9, bmpFondo->Height * 0.9);//dibujando fondo

		//Render
		buffer->Render(g);
	}
private: System::Void FormConfigurarNivel2_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	timer1->Enabled = false;
	this->Close();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int nivel = 2;
	int minutos = Convert::ToInt32(domainUpDown1->Text);
	int segundos = Convert::ToInt32(domainUpDown2->Text);
	int cantAliados = Convert::ToInt32(domainUpDown3->Text);
	int cantHabitantes = Convert::ToInt32(domainUpDown4->Text);
	int cantVacunas = Convert::ToInt32(domainUpDown6->Text);

	//mostrar formulario del juego nivel 1
	this->Visible = false;
	Formulario1^ frmJuego = gcnew Formulario1(minutos, segundos, cantHabitantes, cantAliados, 500, cantVacunas, nivel);
	frmJuego->ShowDialog();
	this->Close();
}
};
}
