using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
using System.Windows.Forms;

namespace DrawLines
{
    public partial class Form1 : Form
    {
        ArrayList ListOfPoints;
        Graphics G;
        Pen P;
        Point cursor;
       // int k = 0;
        //Point[] points = new Point[50];
        bool Pencil;

        public Form1()
        {

            InitializeComponent();
            ListOfPoints = new ArrayList();
            Pencil = false;
            G = this.CreateGraphics();
            P = new Pen(Color.Blue, 5);

        }
        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            Point points = new Point(e.X, e.Y);
            if (Pencil && DrawCheckBox.Checked == true)
            {
                this.statusStrip2.Items[0].Text = "MouseMove";
                if (ListOfPoints.Count > 1)
                    G.DrawLine(P, (Point)ListOfPoints[ListOfPoints.Count-1],points);
                listBoxPoint.Items.Add(e.X +" "+ e.Y);
                ListOfPoints.Add(points);

            }
            cursor = this.PointToClient(Cursor.Position);
            MouseStatue.Text = "X: " + cursor.X + " Y: " + cursor.Y;
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            /*if (DrawCheckBox.Checked == true)
            {
                G.DrawLine(P, cursor.X - 10, cursor.Y - 10, 20, 20);
                points[k++] = new Point(cursor.X, cursor.Y);
                listBoxPoint.Items.Add("X: " + cursor.X + " , Y: " + cursor.Y);
            }*/
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            Point p = new Point(e.X, e.Y);
            ListOfPoints.Add(p);
            Pencil = true;
            this.statusStrip2.Items[0].Text = "MouseDown";
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            Pencil = false;
            this.statusStrip2.Items[0].Text = "MouseUP";

        }
    }
}
