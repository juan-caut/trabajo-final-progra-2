#pragma once

namespace TrabajoF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormInstrucciones
	/// </summary>
	public ref class FormInstrucciones : public System::Windows::Forms::Form
	{
	private:

		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::Button^ button1;

		//fondo del formulario2
		Bitmap^ bmpFondoInstrucciones1;

	public:
		FormInstrucciones(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			//fondo
			bmpFondoInstrucciones1 = gcnew Bitmap("imagenes/fondo_instrucciones.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormInstrucciones()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

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
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormInstrucciones::timer1_Tick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SaddleBrown;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Agency FB", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Gold;
			this->button1->Location = System::Drawing::Point(540, 374);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(216, 50);
			this->button1->TabIndex = 1;
			this->button1->Text = L"volver";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FormInstrucciones::button1_Click);
			// 
			// FormInstrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(768, 430);
			this->ControlBox = false;
			this->Controls->Add(this->button1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(784, 469);
			this->MinimumSize = System::Drawing::Size(784, 469);
			this->Name = L"FormInstrucciones";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EvadeCov-22: Instrucciones";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FormInstrucciones::FormInstrucciones_FormClosed);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		//borrar
		buffer->Graphics->Clear(Color::WhiteSmoke);

		//dibujar
		buffer->Graphics->DrawImage(bmpFondoInstrucciones1, 0, 0, bmpFondoInstrucciones1->Width * 0.6, bmpFondoInstrucciones1->Height * 0.6);//dibujando mapa

		//Render
		buffer->Render(g);
	}
	private: System::Void FormInstrucciones_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		//Cuando se presiona 'X' o se cierra el formulario 
		timer1->Enabled = false;
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
		this->Close();
	}
};
}
