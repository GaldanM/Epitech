using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace MyWindowsMediaPlayer
{
    /// <summary>
    /// Logique d'interaction pour SelectItem.xaml
    /// </summary>
    public partial class SelectItem : Window
    {
        private List<string> listElem;
        
        public SelectItem()
        {
            InitializeComponent();
            listElem = new List<string>();
        }

        List<string> ListElem
        {
            set {
                this.listElem = value;
                foreach (string elem in this.listElem)
                {
                    listBox.Items.Add(elem);
                }
            }
            get { return this.listElem; }
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = true;
        }
    }
}
