namespace CHPlayer
{
    partial class CHPlayer
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CHPlayer));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openVideoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openAudioToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.setupToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.vLCPathToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.installToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.indexToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.button_Sel_Video = new System.Windows.Forms.Button();
            this.button_Sel_Audio = new System.Windows.Forms.Button();
            this.VideoFile = new System.Windows.Forms.TextBox();
            this.AudioFile = new System.Windows.Forms.TextBox();
            this.buttonPlay = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.setupToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(655, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openVideoToolStripMenuItem,
            this.openAudioToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            this.fileToolStripMenuItem.Click += new System.EventHandler(this.fileToolStripMenuItem_Click);
            // 
            // openVideoToolStripMenuItem
            // 
            this.openVideoToolStripMenuItem.Name = "openVideoToolStripMenuItem";
            this.openVideoToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.openVideoToolStripMenuItem.Text = "Open Video";
            this.openVideoToolStripMenuItem.Click += new System.EventHandler(this.openVideoToolStripMenuItem_Click);
            // 
            // openAudioToolStripMenuItem
            // 
            this.openAudioToolStripMenuItem.Name = "openAudioToolStripMenuItem";
            this.openAudioToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.openAudioToolStripMenuItem.Text = "Open Audio";
            this.openAudioToolStripMenuItem.Click += new System.EventHandler(this.openAudioToolStripMenuItem_Click);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // setupToolStripMenuItem
            // 
            this.setupToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.vLCPathToolStripMenuItem,
            this.installToolStripMenuItem});
            this.setupToolStripMenuItem.Name = "setupToolStripMenuItem";
            this.setupToolStripMenuItem.Size = new System.Drawing.Size(49, 20);
            this.setupToolStripMenuItem.Text = "Setup";
            this.setupToolStripMenuItem.Click += new System.EventHandler(this.setupToolStripMenuItem_Click);
            // 
            // vLCPathToolStripMenuItem
            // 
            this.vLCPathToolStripMenuItem.Name = "vLCPathToolStripMenuItem";
            this.vLCPathToolStripMenuItem.Size = new System.Drawing.Size(191, 22);
            this.vLCPathToolStripMenuItem.Text = "VLC Path";
            this.vLCPathToolStripMenuItem.Click += new System.EventHandler(this.vLCPathToolStripMenuItem_Click);
            // 
            // installToolStripMenuItem
            // 
            this.installToolStripMenuItem.Name = "installToolStripMenuItem";
            this.installToolStripMenuItem.Size = new System.Drawing.Size(191, 22);
            this.installToolStripMenuItem.Text = "Install Pornhub Plugin";
            this.installToolStripMenuItem.Click += new System.EventHandler(this.installToolStripMenuItem_Click_1);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.indexToolStripMenuItem,
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // indexToolStripMenuItem
            // 
            this.indexToolStripMenuItem.Name = "indexToolStripMenuItem";
            this.indexToolStripMenuItem.Size = new System.Drawing.Size(107, 22);
            this.indexToolStripMenuItem.Text = "Index";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(107, 22);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // button_Sel_Video
            // 
            this.button_Sel_Video.Location = new System.Drawing.Point(521, 56);
            this.button_Sel_Video.Name = "button_Sel_Video";
            this.button_Sel_Video.Size = new System.Drawing.Size(78, 23);
            this.button_Sel_Video.TabIndex = 1;
            this.button_Sel_Video.Text = "Select Video";
            this.button_Sel_Video.UseVisualStyleBackColor = true;
            this.button_Sel_Video.Click += new System.EventHandler(this.button_Sel_VideoFile_Click);
            // 
            // button_Sel_Audio
            // 
            this.button_Sel_Audio.Location = new System.Drawing.Point(521, 118);
            this.button_Sel_Audio.Name = "button_Sel_Audio";
            this.button_Sel_Audio.Size = new System.Drawing.Size(78, 23);
            this.button_Sel_Audio.TabIndex = 2;
            this.button_Sel_Audio.Text = "Select Audio";
            this.button_Sel_Audio.UseVisualStyleBackColor = true;
            this.button_Sel_Audio.Click += new System.EventHandler(this.button_Sel_Audio_Click);
            // 
            // VideoFile
            // 
            this.VideoFile.Location = new System.Drawing.Point(22, 59);
            this.VideoFile.Name = "VideoFile";
            this.VideoFile.Size = new System.Drawing.Size(481, 20);
            this.VideoFile.TabIndex = 3;
            this.VideoFile.Text = "e:\\Privat Download\\CH Video\\Cock Hero\\CH Flux - Episode 4 hard\\CH Flux - Episode " +
    "04 StL.mp4";
            // 
            // AudioFile
            // 
            this.AudioFile.Location = new System.Drawing.Point(22, 120);
            this.AudioFile.Name = "AudioFile";
            this.AudioFile.Size = new System.Drawing.Size(481, 20);
            this.AudioFile.TabIndex = 4;
            this.AudioFile.Text = "e:\\Privat Download\\CH Video\\Cock Hero\\CH Flux - Episode 4 hard\\CH Flux - Episode " +
    "04 StL.mp3";
            // 
            // buttonPlay
            // 
            this.buttonPlay.Location = new System.Drawing.Point(486, 159);
            this.buttonPlay.Name = "buttonPlay";
            this.buttonPlay.Size = new System.Drawing.Size(113, 28);
            this.buttonPlay.TabIndex = 7;
            this.buttonPlay.Text = "Play Video in VLC";
            this.buttonPlay.UseVisualStyleBackColor = true;
            this.buttonPlay.Click += new System.EventHandler(this.buttonPlay_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(19, 43);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(156, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "Select Video File or Paste URL:";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(19, 104);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(89, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "Select Audio File:";
            // 
            // CHPlayer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(655, 199);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonPlay);
            this.Controls.Add(this.AudioFile);
            this.Controls.Add(this.VideoFile);
            this.Controls.Add(this.button_Sel_Audio);
            this.Controls.Add(this.button_Sel_Video);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "CHPlayer";
            this.Text = "CHPlayer";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openVideoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openAudioToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem setupToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem vLCPathToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem indexToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem installToolStripMenuItem;
        private System.Windows.Forms.Button button_Sel_Video;
        private System.Windows.Forms.Button button_Sel_Audio;
        private System.Windows.Forms.TextBox VideoFile;
        private System.Windows.Forms.TextBox AudioFile;
        private System.Windows.Forms.Button buttonPlay;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}

