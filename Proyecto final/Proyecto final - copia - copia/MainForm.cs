/*
 * Created by SharpDevelop.
 * User: Joshyba
 * Date: 07/03/2013
 * Time: 01:33 p.m.
 * 
 * Desarrollador: Ing. José israel Gómez Rodríguez
 * web: http://joshybadevelopments.blogspot.mx
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace ahorcado
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		// declarando los temas y sus respectivas palabras
		private string[] cosas={
		"ventilador",
		"mesa",
		"refrigerador",
		"television",
		"ropero",
		"estufa",
		"baño",
		"linterna",
		"cama",
		"silla",
		"sillon",
		"ventana",
		"espejo",
		"foco",
		"cortina",
		"puerta",
		"sofa",
		"almohada",
		"sabanas",
		"modular",
		};
		private string[] animales={
			"gato",
			"perro",
			"burro",
			"elefante",
			"gaviota",
			"delfin",
			"vibora",
			"foca",
			"ballena",
			"gusano",
			"hamster",
			"leon",
			"puma",
			"cebra",
			"mono",
			"vaca",
			"caballo",
			"rinoceronte",
			"loro",
			"pescado",
			"camaron",
			"tortuga",
		};
		private string[] cuerpo={
			"cabeza",
			"orejas",
			"nariz",
			"ojos",
			"labios",
			"boca",
			"pestañas",
			"dedos",
			"pies",
			"tobillo",
			"codo",
			"rodilla",
			"brazos",
			"pecho",
			"antebrazo",
		};
		private string[] fruver={
			"manzana",
			"apio",
			"mango",
			"zanahoria",
			"platano",
			"calabaza",
			"fresa",
			"frambuesa",
			"papaya",
			"aguacate",
			"brocoli",
			"cebolla",
			"betabel",
			"uva",
			"chayote",
			"rabano",
			"cilantro",
		};
		private string[] materias={
			"español",
			"matematicas",
			"geografia",
			"historia",
			"civismo",
			"ingles",
			"frances",
			"biologia",
			"quimica",
			"fisica",
			"sociales",
		};
		//imagenes del ahorcado
		private string[] imagenes={
			"aho1_.PNG",
			"aho2_.PNG",
			"aho3_.PNG",
			"aho4_.PNG",
			"aho5_.PNG",
			"aho6_.PNG",
			"aho7_.PNG",
			"aho8_.PNG",
			"aho9_.PNG",
			"aho10_.PNG",
		};
		//variables globales
		private int buenas=0; //numero de buenas			
		private string antes; //cadena que contiene la palabra antes del keypress
		private string PabElegida; //es la palabra seleccionada
		private bool Jugar=false;  //variable bool k dice si se esta jugando
		private int malas=-1;  //numero de las malas
		private int num_text=0; //numero de la palabra elegida del tema elegido
		private int tamanio;  //cantidad de letras de la palabra general
		private int cant=0; //cantidad de letras exactas
		private int tema_elegido; //numero del tema elegido
		//private int largo_arreglo; //numero del tamaño del tema elegido
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		
		void MainFormShown(object sender, EventArgs e)
		{
		}
		
		void MainFormLoad(object sender, EventArgs e)
		{
		}
		public void Iniciar_juego(){
			groupBox1.Visible=false;//oculta panel de eleccion del tema
			PabElegida=temas(tema_elegido);//tiene la palabra elegida
			tamanio=PabElegida.Length;//guarda el tamaño de la palabra elegida
			Crear_texto();//modifica el texbox exclusivo para esa palabra
			Count_Letras(PabElegida);//cuenta las letras de la palabra elegida
			cant++;//debido a que mi contador falla incremento uno mas a la variable+
			//global cant
			//muestro la cantidad de letras de la palabra elegida
			label1.Text="Tiene "+PabElegida.Length.ToString()+" letras";
			Jugar=true;//activo que ya se esta jugando
			maskedTextBox1.Focus();//y pongo el foco en el maskedtexbox
		}
		public void Buscar_palabra(int cantcad){
			Random a =new Random();
			num_text=a.Next(0,cantcad);
			//MessageBox.Show(num_text.ToString());
		}
		public string temas(int Var){
			string Tema_Ele="";
			switch(Var){
				case 1://tema cosas elegido
					Buscar_palabra(cosas.Length);//se envia el tamaño
					Tema_Ele = cosas[num_text];//y después el numero del pala palabra elegida
					break;
				case 2:
					Buscar_palabra(materias.Length);
					Tema_Ele = materias[num_text];
					break;
				case 3:
					Buscar_palabra(animales.Length);
					Tema_Ele = animales[num_text];
					break;
				case 4:
					Buscar_palabra(cuerpo.Length);
					Tema_Ele = cuerpo[num_text];
					break;
				case 5:
					Buscar_palabra(fruver.Length);
					Tema_Ele = fruver[num_text];
					break;
			}
			return Tema_Ele;//se retorna la palabra elegida
		}
		public void Count_Letras(string cadelegida){
			cant++;//incrementa en uno ya que se reviza la prime letra con todas
			string precount=cadelegida;//se almacena la palabra elegida
			string precount2="",precount3="";//dos variable de apoyo
			for(int x=0;x<precount.Length;x++){//se recorre cada palabra con el tamaño de la palabra elegida
				precount2=precount.Substring(0,1);//primera letra por defecto se guarda
				if(precount2!=precount.Substring(x,1)){//si esta es diferente se 
					precount3+=precount.Substring(x,1);// concatena en la tercer varible
				}
			}
			if(precount3.Length!=1)//cuando queda mas de una palabra se sigue
				Count_Letras(precount3);//llamando solita la funcion 
		}
		public void Crear_texto(){
			//casa 4  para progrmacion 4-1 =3
			string mas="";//varible vacia que guardara la palabra final
			for(int i=1;i<=tamanio;i++)//limite de letras de la variable tamanio
			{
				mas+="-a";//concatena la mascara para el maskedtexbox
				antes+="- ";//concatena la palabra guionvacio para un buen conteo de letras
			}
			this.maskedTextBox1.Mask = mas;//se modifica la mascara del maskedtexbox
		}
		void MainFormKeyPress(object sender, KeyPressEventArgs e)
		{
			///MessageBox.Show("presionando una tecla");
		}
		void MaskedTextBox1KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
		{
			if(Jugar==true)
			{
				//MessageBox.Show("Joshyba");
				texto_ver(e);
			}
		}
		public void texto_ver(System.Windows.Forms.KeyPressEventArgs e)
		{
		//checando si esta la ala letra
			bool esta=false;//bandera si se encuentra la letra elegida
			string mas2="";//cadena de ayuda
			//tamaño de la palabra elegida
			/*si la palabra elegida elegida está se concatena a la varible mas
			 * de lo contrario se concatena guion mas vacio a la varible mas
			 * para checar que la letra se convierte a minuscula.
			 * se modifica tambien la bandera esta en verdadero*/
			for(int x=0;x<PabElegida.Length;x++)
			{
				if(PabElegida.Substring(x,1)==e.KeyChar.ToString().ToLower())
				{
					mas2+=("-"+e.KeyChar.ToString());
					esta=true;
				}
				else{
					mas2+="- ";
				}
			}
			//completar cadena
			//se crean una varible para la candena final despues de revizar si esta o no
			// y una bandera para no aumentar mucho las buenas por la repeticion
			// de las letras como casa que serian 2 veces
			string mientras="";bool gt=true;
			/*para ello se toma el tamaño de la varible global antes
			 * que contiene al el valor del tipo cadena del maskedTextBox
			 * si antes.vacio es igual igual a vacio y
			 * la cadena de ayuda anterior es diferente de vacio
			 * entonces se contatena a mientras osea la letra precionada*/
			for(int y=0;y<antes.Length;y=y+2)
			{
				if(antes.Substring(y,2)=="- " && mas2.Substring(y,2)!="- "){
					mientras+=mas2.Substring(y,2);
					if(gt==true)buenas++;//si fue verda k de ley asi se incrementa buenas
					gt=false;// y se pone falso para que no cuente las demas letras que se repiten en la palabra
				}
				else{
					mientras+=antes.Substring(y,2);//de lo contrartio se sigue poniendo vacio
				}
			}
			this.maskedTextBox1.Text=mientras;// se modifica el valor de maskedTexBox
			antes=mientras;//y se vuelve a guardar esto en antes para su proxima revision
			if(esta==false){//si no estaba se:
			malas++; //incrementa malas y
			listBox1.Items.Add(e.KeyChar.ToString());// se añade al ListBox
			} 
			if(malas>-1)//si malas es mayor que -1 entonces se nuestra la respectiva imagen en el picture
				pictureBox1.ImageLocation="images/"+imagenes[malas];
			if(malas==9){//si malas llega a nueves se muestra el msj perdio y se reseta el juego
					MessageBox.Show("HAS PERDIDO,JA JA JA");
					reset();
			}		
			esta=false;//por ulimo no se esta jugando
		}
		
		void MaskedTextBox1KeyUp(object sender, KeyEventArgs e)
		{
			this.maskedTextBox1.Text=antes;
			if(buenas==cant && malas<10){
					MessageBox.Show("FELICIDADES");
					reset();
			}
		}
		
		void Button1Click(object sender, EventArgs e)
		{
			//tema elegido
			if(radioButton1.Checked==true){
				tema_elegido=1;//variable global tema a tema 1
				Iniciar_juego();//llamar la funcion iniciar juego
			}
			else if(radioButton2.Checked==true){
				tema_elegido=2;
				Iniciar_juego();
			}
			else if(radioButton3.Checked==true){
				tema_elegido=3;
				Iniciar_juego();
			}
			else if(radioButton4.Checked==true){
				tema_elegido=4;
				Iniciar_juego();				
			}
			else if(radioButton5.Checked==true){
				tema_elegido=5;
				Iniciar_juego();
			}
			else// de los contrario mostrar que no se eligio nada
				MessageBox.Show("elige una opcion","el ahorcado");			
		}
		public void reset(){
			groupBox1.Visible=true;//Muestra el grupo de texto
			listBox1.Items.Clear(); //vacia el lixbox
			maskedTextBox1.Clear(); //resetea el maskedtext
			pictureBox1.ImageLocation="images/vacio.PNG";//muestra una imagen vacia
			malas=-1;//malas se vuelve a resetar
			antes="";//se vacia la cadena
			PabElegida="";//se vacia la cadena	
		}
	}           
	
}
