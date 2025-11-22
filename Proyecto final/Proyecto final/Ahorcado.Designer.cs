namespace Proyecto_final
{
    partial class Ahorcado
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Ahorcado));
            this.Iniciar = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Iniciar
            // 
            this.Iniciar.Cursor = System.Windows.Forms.Cursors.Default;
            resources.ApplyResources(this.Iniciar, "Iniciar");
            this.Iniciar.Name = "Iniciar";
            this.Iniciar.UseVisualStyleBackColor = true;
            this.Iniciar.Click += new System.EventHandler(this.button1_Click);
            // 
            // Ahorcado
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Highlight;
            this.ControlBox = false;
            this.Controls.Add(this.Iniciar);
            this.Cursor = System.Windows.Forms.Cursors.Default;
            this.Name = "Ahorcado";
            this.TopMost = true;
            this.TransparencyKey = System.Drawing.SystemColors.Highlight;
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button Iniciar;
    }
}

