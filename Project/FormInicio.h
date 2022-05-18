#pragma once
#include "FormElegirNivel.h"
#include"FormCreditos.h"
#include"FormInstrucciones.h"

namespace TrabajoF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Formulario2
	/// </summary>
	public ref class Formulario2 : public System::Windows::Forms::Form
	{
	private:

		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//fondo del formulario2
		Bitmap^ bmpFondoInicio;

		//music
		SoundPlayer^ spMusicInicio;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	public:
		Formulario2(void)
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
			bmpFondoInicio = gcnew Bitmap("imagenes/fondo_inicio.jpeg");

			//audio
			spMusicInicio = gcnew SoundPlayer("sonidos/audio_inicio.wav");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Formulario2()
		{
			if (components)
			{
				delete components;
			}
		}
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Formulario2::timer1_Tick);
			// 
			// button1
			// 
			this->button1->AccessibleDescription = L"";
			this->button1->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Agency FB", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Gold;
			this->button1->Location = System::Drawing::Point(12, 117);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(209, 46);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Jugar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Formulario2::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Agency FB", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Gold;
			this->button2->Location = System::Drawing::Point(12, 171);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(209, 46);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Instrucciones";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Formulario2::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Font = (gcnew System::Drawing::Font(L"Agency FB", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Gold;
			this->button3->Location = System::Drawing::Point(12, 227);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(209, 46);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Créditos\r\n";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Formulario2::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Font = (gcnew System::Drawing::Font(L"Agency FB", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Gold;
			this->button4->Location = System::Drawing::Point(12, 283);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(209, 46);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Salir";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Formulario2::button4_Click);
			// 
			// Formulario2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(768, 430);
			this->ControlBox = false;
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(784, 469);
			this->MinimumSize = System::Drawing::Size(784, 469);
			this->Name = L"Formulario2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EvadeCov-22: Inicio";
			this->Load += gcnew System::EventHandler(this, &Formulario2::Formulario2_Load);
			this->ResumeLayout(false);

		}


#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		
		//borrar
		buffer->Graphics->Clear(Color::WhiteSmoke);

		//dibujar
		buffer->Graphics->DrawImage(bmpFondoInicio, 0, 0, bmpFondoInicio->Width * 0.6, bmpFondoInicio->Height * 0.6);//dibujando mapa

		//Render
		buffer->Render(g);
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//
	this->Visible = false;
	FormElegirNivel^ frmN = gcnew FormElegirNivel(spMusicInicio);
	frmN->ShowDialog();
	this->Visible = true;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Visible = false;
	FormCreditos^ frmC = gcnew FormCreditos();
	frmC->ShowDialog();
	this->Visible = true;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Visible = false;
	FormInstrucciones^ frmI = gcnew FormInstrucciones();
	frmI->ShowDialog();
	this->Visible = true;
}
private: System::Void Formulario2_Load(System::Object^ sender, System::EventArgs^ e) {
	spMusicInicio->PlayLooping();
}
};
}
