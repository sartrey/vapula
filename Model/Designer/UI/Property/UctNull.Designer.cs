﻿namespace TCM.Model.Designer
{
    partial class UctNull
    {
        /// <summary> 
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region 组件设计器生成的代码

        /// <summary> 
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.Lbl1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Lbl1
            // 
            this.Lbl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.Lbl1.Location = new System.Drawing.Point(0, 0);
            this.Lbl1.Name = "Lbl1";
            this.Lbl1.Size = new System.Drawing.Size(350, 200);
            this.Lbl1.TabIndex = 0;
            this.Lbl1.Text = "您没有选择对象，\r\n\r\n或选择的对象没有可以操作的属性。";
            this.Lbl1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // UctNull
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.Lbl1);
            this.Name = "UctNull";
            this.Size = new System.Drawing.Size(350, 200);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label Lbl1;
    }
}