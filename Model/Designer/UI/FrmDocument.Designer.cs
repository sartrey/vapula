﻿namespace TCM.Model.Designer
{
    partial class FrmDocument
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
            this.components = new System.ComponentModel.Container();
            this.ctxmenubar = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.MnuDebugCanvas = new System.Windows.Forms.ToolStripMenuItem();
            this.MnuDebugGraph = new System.Windows.Forms.ToolStripMenuItem();
            this.ctxmenubar.SuspendLayout();
            this.SuspendLayout();
            // 
            // ctxmenubar
            // 
            this.ctxmenubar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MnuDebugCanvas,
            this.MnuDebugGraph});
            this.ctxmenubar.Name = "ctxmenubar";
            this.ctxmenubar.Size = new System.Drawing.Size(141, 48);
            // 
            // MnuDebugCanvas
            // 
            this.MnuDebugCanvas.Name = "MnuDebugCanvas";
            this.MnuDebugCanvas.Size = new System.Drawing.Size(152, 22);
            this.MnuDebugCanvas.Text = "调试画布(&C)";
            this.MnuDebugCanvas.Click += new System.EventHandler(this.MnuDebugCanvas_Click);
            // 
            // MnuDebugGraph
            // 
            this.MnuDebugGraph.Name = "MnuDebugGraph";
            this.MnuDebugGraph.Size = new System.Drawing.Size(152, 22);
            this.MnuDebugGraph.Text = "调试图(&G)";
            this.MnuDebugGraph.Click += new System.EventHandler(this.MnuDebugGraph_Click);
            // 
            // FrmDocument
            // 
            this.AllowDrop = true;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(184, 162);
            this.DockAreas = ((xDockPanel.DockAreas)((xDockPanel.DockAreas.Float | xDockPanel.DockAreas.Document)));
            this.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Name = "FrmDocument";
            this.SizeChanged += new System.EventHandler(this.FrmDocument_SizeChanged);
            this.MouseClick += new System.Windows.Forms.MouseEventHandler(this.FrmDocument_MouseClick);
            this.ctxmenubar.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ContextMenuStrip ctxmenubar;
        private System.Windows.Forms.ToolStripMenuItem MnuDebugCanvas;
        private System.Windows.Forms.ToolStripMenuItem MnuDebugGraph;

    }
}