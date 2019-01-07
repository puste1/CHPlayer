using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Net; 
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CHPlayer
{
    public partial class CHPlayer : Form
    {
        string sVLC = "";
        string sVideo = "";
        string sAudio = "";

        public CHPlayer()
        {
            InitializeComponent();
            // Load save Path to VLC Program
            sVLC = Properties.Settings.Default.pathVLC;
            sVideo = Properties.Settings.Default.pathVideo;
            sAudio = Properties.Settings.Default.pathAudio;
        }

        private void fileToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        //*****************************************************************************************
        // Bottom Select Video   
        //*****************************************************************************************
        private void button_Sel_VideoFile_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "Cursor Files|*.mp4";
            openFileDialog1.Title = "Select a MP4 Video File";
            if (openFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                // Assign the cursor in the Stream to the Form's Cursor property.  
                this.VideoFile.Text = openFileDialog1.FileName;
            }
        }

        //*****************************************************************************************
        // Bottom Select Audio  
        //*****************************************************************************************
        private void button_Sel_Audio_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "Cursor Files|*.mp3";
            openFileDialog1.Title = "Select a MP3 Audio File";
            if (openFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                // Assign the cursor in the Stream to the Form's Cur

                this.AudioFile.Text = openFileDialog1.FileName;
            }
        }

        //*****************************************************************************************
        // Bottom Play Start VLC 
        //*****************************************************************************************
        private void buttonPlay_Click(object sender, EventArgs e)
        {
            //string pathVLC = "C:\\Program Files\\VideoLAN\\VLC\\vlc.exe";
            
            System.Diagnostics.Process VLC = new System.Diagnostics.Process();
            //VLC.StartInfo.FileName = pathVLC; 
            VLC.StartInfo.FileName = sVLC;

                                    
            // Set Argument for VLC (Select Estim Audio for selected Video)
            VLC.StartInfo.Arguments = string.Format("\"{0}\" {1}\" {2}\" {3}", 
                 @VideoFile.Text, 
                 " --input-slave ", 
                 AudioFile.Text, 
                 " --audio-track=1");

            
            // Save Path to VLC program 
            Properties.Settings.Default.pathVideo = @VideoFile.Text;
            Properties.Settings.Default.pathVideo = @AudioFile.Text;
            // Start VLC
            VLC.Start();
        }


        //*****************************************************************************************
        // Exit Aplcation  
        //*****************************************************************************************
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        //*****************************************************************************************
        // Set link to VLC Program
        //*****************************************************************************************
        private void vLCPathToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string value = @"C:\Program Files\VideoLAN\VLC\vlc.exe"; 
            if (CHPlayer.InputBox("Save VLC Program Link", "Link to VLC Program:", ref value) == DialogResult.OK)
            {
                // Save Link 
                Properties.Settings.Default.pathVLC = value;
                // Use Link
                sVLC = value;
            }
        }

        //*****************************************************************************************
        // Create Form for input 
        //*****************************************************************************************
        public static DialogResult InputBox(string title, string promptText, ref string value)
        {
            Form form = new Form();
            Label label = new Label();
            TextBox textBox = new TextBox();
            Button buttonOk = new Button();
            Button buttonCancel = new Button();

            form.Text = title;
            label.Text = promptText;
            textBox.Text = value;

            buttonOk.Text = "OK";
            buttonCancel.Text = "Cancel";
            buttonOk.DialogResult = DialogResult.OK;
            buttonCancel.DialogResult = DialogResult.Cancel;

            label.SetBounds(9, 20, 372, 13);
            textBox.SetBounds(12, 36, 372, 20);
            buttonOk.SetBounds(228, 72, 75, 23);
            buttonCancel.SetBounds(309, 72, 75, 23);

            label.AutoSize = true;
            textBox.Anchor = textBox.Anchor | AnchorStyles.Right;
            buttonOk.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
            buttonCancel.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;

            form.ClientSize = new Size(396, 107);
            form.Controls.AddRange(new Control[] { label, textBox, buttonOk, buttonCancel });
            form.ClientSize = new Size(Math.Max(300, label.Right + 10), form.ClientSize.Height);
            form.FormBorderStyle = FormBorderStyle.FixedDialog;
            form.StartPosition = FormStartPosition.CenterScreen;
            form.MinimizeBox = false;
            form.MaximizeBox = false;
            form.AcceptButton = buttonOk;
            form.CancelButton = buttonCancel;

            DialogResult dialogResult = form.ShowDialog();
            value = textBox.Text;
            return dialogResult;
        }

        private void installToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        //*****************************************************************************************
        // Setup plugin for PornHub for VLC
        //*****************************************************************************************
        private void installToolStripMenuItem_Click_1(object sender, EventArgs e)
        {

            // Setup %Appdata% Directory for VLC
            var appDataPath = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData);
            var path = Path.Combine(appDataPath, @"vlc\lua\playlist");

            // Create Directory if not Exist
            if (!Directory.Exists(path))
                Directory.CreateDirectory(path);

            // Copy PornHub plugin File from C:\temp to %Appdata%\vlc\lua\playlist\ 
            string sourceFile = @"C:\temp\pornhub.lua";
            string destFile = path + @"\pornhub.lua";
            System.IO.File.Copy(sourceFile, destFile, true);

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void openVideoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            button_Sel_VideoFile_Click(sender, EventArgs.Empty);
        }

        private void openAudioToolStripMenuItem_Click(object sender, EventArgs e)
        {
            button_Sel_Audio_Click(sender, EventArgs.Empty);
        }

        private void setupToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        //*****************************************************************************************
        // Show About Box
        //*****************************************************************************************
        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Show AboutBox
            AboutBox1 a = new AboutBox1();
            a.Show();

        }
    }
}
