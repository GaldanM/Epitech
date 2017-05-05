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
using System.Windows.Navigation;
using System.Windows.Shapes;
using LoginDropBox;
using Dropbox.Api;

namespace MyCloud
{
    public partial class MainWindow : Window
    {
        Database _Database;
        List<string> mylist = new List<string>(new string[] { "element1element1element1element1", "element2", "element3", "element2", "element2", "element2", "element2", "element2", "element2", "element2", "element2", "element2", "element2" });
        List<TreeViewItem> _Accounts;

        public MainWindow()
        {
            InitializeComponent();
            _Database = new Database();
            InitTrees();
        }

        private void InitTrees()
        {
            _Accounts = new List<TreeViewItem>();

            _Accounts.Add(new TreeViewItem());
            _Accounts[0].Header = "DropBox";
            updateDropBoxTree();

            _Accounts.Add(new TreeViewItem());
            _Accounts[1].Header = "Google Drive";
        }

        private void loadDropBox(object sender, RoutedEventArgs e)
        {
            var tree = sender as TreeView;
            tree.Items.Add(_Accounts[0]);
        }
        
        private void loadGDrive(object sender, RoutedEventArgs e)
        {
            var tree = sender as TreeView;
            tree.Items.Add(_Accounts[1]);
        }

        private void _treeView_MouseUp(object sender, MouseButtonEventArgs e)
        {
            TreeView tv = sender as TreeView;
            TreeViewItem tvi = tv.SelectedItem as TreeViewItem;
            if (tvi != null)
                tvi.IsExpanded = !tvi.IsExpanded;
        }

        private void _treeView_PreviewMouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            e.Handled = true;
        }

        private void bAddDropBox_Click(object sender, RoutedEventArgs e)
        {
            String          token;
            String          email;
            DropboxClient   dbc;
            LoginForm       loginForm;

            loginForm = new LoginForm("h4ly6w01v4hyjw6");
            loginForm.ShowDialog();

            if (loginForm.Result == true)
            {
               token = loginForm.AccessToken;
                dbc = new DropboxClient(token);

                var task = Task.Run(() => getEmailDropbox(dbc));
                task.Wait();

                email = task.Result;
                if (_Database.addDropBoxAccount(token, email) == false)
                    MessageBox.Show(email + " is already registered on MyCloud, look to the left ! :-)");
                updateDropBoxTree();
            }
        }

        static async Task<string> getEmailDropbox(DropboxClient dbc)
        {
            var full = await dbc.Users.GetCurrentAccountAsync();
            return full.Email;
        }

        private void updateDropBoxTree()
        {
            List<String> accs = new List<String>();

            foreach (Account acc in _Database.getDropBoxAccounts())
                accs.Add(acc.Email);
            _Accounts[0].ItemsSource = accs;
        }
    }

    public class TreeViewEx : TreeView
    {
        protected override void OnPreviewMouseDoubleClick(MouseButtonEventArgs e)
        {
            e.Handled = true;
            base.OnPreviewMouseDoubleClick(e);  
        }
    }
}
