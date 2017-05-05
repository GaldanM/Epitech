using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Forms;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Controls.Primitives;

namespace MyWindowsMediaPlayer
{
    /// <summary>
    /// Logique d'interaction pour MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private PlaylistElem _Current;
        private PlaylistElem _Music;
        private PlaylistElem _Video;
        private PlaylistElem _Image;
        private List<Media>  _Medias;
        private TreeViewItem _Item;
        private Database     _Db;
        private HeaderDirection _HrDir;
        private int _mediaIndex = 0;
        private string _currentFolderName = null;
        private string _currentPlaylistName = null;

        public MainWindow()
        {
            InitializeComponent();
            _Db = new Database();
            _HrDir = new HeaderDirection();
            _Medias = new List<Media>();
            init_tree();
            _Current = new PlaylistElem("Current");
            _Video = new PlaylistElem("Video");
            _Music = new PlaylistElem("Music");
            _Image = new PlaylistElem("Image");
        }

        private void init_tree()
        {
            _Item = new TreeViewItem();
            _Item.Header = "Playlist";
            TreeView.Items.Add(_Item);
            List<string> playlist = _Db.getPlaylists();
            foreach (string elem in playlist)
            {
                create_item_tree(elem);
            }
        }

        private void buttonPlay_Click(object sender, RoutedEventArgs e)
        {
            setStatus();
            playMedia();
        }

        private void buttonPause_Click(object sender, RoutedEventArgs e)
        {
            videoDisplay.Pause();
        }

        private void buttonStop_Click(object sender, RoutedEventArgs e)
        {
            videoDisplay.Stop();
            show_listBox();
        }

        private void videoDisplay_MediaEnded(object sender, RoutedEventArgs e)
        {
            nextMedia();
        }

        private void nextMedia()
        {
            _mediaIndex = 0;
            foreach (Media elem in _Medias)
            {
                if (new Uri(elem.Path).AbsolutePath == videoDisplay.Source.AbsolutePath)
                {
                    if (_Medias.Count() > _mediaIndex + 1)
                    {
                        videoDisplay.Source = new Uri(_Medias.ElementAt(_mediaIndex + 1).Path);
                        videoDisplay.Play();
                        return;
                    }
                }
                _mediaIndex++;
            }
            videoDisplay.Stop();
            show_listBox();
        }

        private void buttonBack_Click(object sender, RoutedEventArgs e)
        {
            _mediaIndex = 0;
            foreach (Media elem in _Medias)
            {
                if (new Uri(elem.Path).AbsolutePath == videoDisplay.Source.AbsolutePath)
                {
                    if (_mediaIndex - 1 >= 0)
                    {
                        videoDisplay.Source = new Uri(_Medias.ElementAt(_mediaIndex - 1).Path);
                        videoDisplay.Play();
                        return;
                    }
                }
                _mediaIndex++;
            }
            videoDisplay.Stop();
            show_listBox();
        }

        private void buttonNext_Click(object sender, RoutedEventArgs e)
        {
            nextMedia();
        }

        private void buttonStorage_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog file;
            file = new OpenFileDialog();
            file.AddExtension = true;
            file.DefaultExt = "*.*";
            file.Filter = "Media Files (*.*)|*.*";
            file.ShowDialog();

            try
            {
                _currentFolderName = null;
                _currentPlaylistName = null;
                videoDisplay.Source = new Uri(file.FileName);
                Uri uri = new Uri(file.FileName);
                Media elem = null;
                if (uri.IsFile)
                {
                    string filename = System.IO.Path.GetFileName(uri.LocalPath);
                    elem = Database.getMedia(file.FileName);
                }
                ListBoxItem itm = new ListBoxItem();
                itm.Content = elem.Title;
                
                itm.MouseDoubleClick += Itm_MouseDoubleClick;
                bool doublon = false;
                foreach (Media element in _Current.Content)
                {
                    if (element.Path == elem.Path)
                    {
                        doublon = true;
                        break;
                    }
                }
                if (!doublon)
                    _Current.Content.Add(elem);
                fill_listbox(_Current.Content);
            }

            catch { new NullReferenceException("Error"); }

            System.Windows.Threading.DispatcherTimer dispatcherTimer = new System.Windows.Threading.DispatcherTimer();
            dispatcherTimer.Tick += new EventHandler(timer_Tick);
            dispatcherTimer.Interval = new TimeSpan(0, 0, 1);
            dispatcherTimer.Start();
        }

        private void Itm_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            string currentMedia = Convert.ToString(listBox.SelectedItem).Replace("System.Windows.Controls.ListBoxItem: ", "");

            var medias = from media in _Medias
                        where media.Title == currentMedia
                        select media;

            Media med = null;
            if (medias.Any())
            {
                med = medias.FirstOrDefault();
            }

            setStatus();
            videoDisplay.Source = new Uri(med.Path);
            playMedia();
        }

        void timer_Tick(object sender, EventArgs e)
        {
            sliderVideo.Value = videoDisplay.Position.TotalSeconds;
        }

        private void sliderVideo_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            TimeSpan ts = TimeSpan.FromSeconds(e.NewValue);
            videoDisplay.Position = ts;
        }

        private void sliderVolume_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            videoDisplay.Volume = sliderVolume.Value;
        }

        private void videoDisplay_MediaOpened(object sender, RoutedEventArgs e)
        {
            if (videoDisplay.NaturalDuration.HasTimeSpan)
            {
                TimeSpan ts = TimeSpan.FromMilliseconds(videoDisplay.NaturalDuration.TimeSpan.TotalMilliseconds);
                sliderVideo.Maximum = ts.TotalSeconds;
            }
        }

        private void free_states()
        {
            _Current.State = false;
            _Music.State = false;
            _Video.State = false;
            _Image.State = false;
        }

        private void free_playing_states()
        {
            _Current.IsPlaying = false;
            _Music.IsPlaying = false;
            _Video.IsPlaying = false;
            _Image.IsPlaying = false;
        }

        private void setStatus()
        {
            if (_Current.State)
            {
                free_playing_states();
                _Current.IsPlaying = true;
            }
            else if (_Video.State)
            {
                free_playing_states();
                _Video.IsPlaying = true;
            }
            else if (_Music.State)
            {
                free_playing_states();
                _Music.IsPlaying = true;
            }
            else if (_Image.State)
            {
                free_playing_states();
                _Image.IsPlaying = true;
            }
        }

        private void show_listBox()
        {
            videoDisplay.Visibility = Visibility.Hidden;
            listBox.Visibility = Visibility.Visible;
        }

        private void hide_listBox()
        {
            videoDisplay.Visibility = Visibility.Visible;
            listBox.Visibility = Visibility.Hidden;
        }

        private void playMedia()
        {
            hide_listBox();
            videoDisplay.Play();
            System.Windows.Threading.DispatcherTimer dispatcherTimer = new System.Windows.Threading.DispatcherTimer();
            dispatcherTimer.Tick += new EventHandler(timer_Tick);
            dispatcherTimer.Interval = new TimeSpan(0, 0, 1);
            dispatcherTimer.Start();
        }

        public void fill_listbox(List<Media> list)
        {
            listBox.Items.Clear();
            foreach (Media element in list)
            {
                listBox.Items.Add(new ListViewItems { Title = element.Title, Time = element.Length, Album = element.Album, Artiste = element.Artist } );
            }
        }

        public void ListViewItem_click(object sender, MouseButtonEventArgs e)
        {
            ListViewItems currentMedia = (ListViewItems)listBox.SelectedItem;
            if (_currentPlaylistName == null && _currentFolderName == null)
                _Medias = _Current.Content;

            var medias = from media in _Medias
                         where media.Title == currentMedia.Title
                         select media;

            Media med = null;
            if (medias.Any())
            {
                med = medias.FirstOrDefault();
            }
            setStatus();
            videoDisplay.Source = new Uri(med.Path);
            playMedia();
        }

        private void buttonCurrent_Click(object sender, RoutedEventArgs e)
        {
            _currentFolderName = null;
            _currentPlaylistName = null;
            free_states();
            _Current.State = true;
            if (!_Current.IsPlaying)
                show_listBox();
            else
                hide_listBox();
            fill_listbox(_Current.Content);
        }

        private void buttonMusic_Click(object sender, RoutedEventArgs e)
        {
            free_states();
            _Current.State = true;
            if (!_Music.IsPlaying)
                show_listBox();
            else
                hide_listBox();
            change_folder_name(Environment.GetFolderPath(Environment.SpecialFolder.MyMusic));
            _Medias = Database.getMediasFromFolder(Environment.GetFolderPath(Environment.SpecialFolder.MyMusic));
            _Music.Content.Clear();
            foreach (Media key in _Medias)
            {
                _Music.Content.Add(key);
            }
            fill_listbox(_Music.Content);
        }

        private void buttonImage_Click(object sender, RoutedEventArgs e)
        {

            free_states();
            _Current.State = true;
            if (!_Music.IsPlaying)
                show_listBox();
            else
                hide_listBox();
            change_folder_name(Environment.GetFolderPath(Environment.SpecialFolder.MyPictures));
            _Medias = Database.getMediasFromFolder(Environment.GetFolderPath(Environment.SpecialFolder.MyPictures));
            _Image.Content.Clear();
            foreach (Media key in _Medias)
            {
                _Image.Content.Add(key);
            }
            fill_listbox(_Image.Content);
        }

        private void buttonVideo_Click(object sender, RoutedEventArgs e)
        {
            free_states();
            _Video.State = true;
            if (!_Video.IsPlaying)
                show_listBox();
            else
                hide_listBox();
            change_folder_name(Environment.GetFolderPath(Environment.SpecialFolder.MyVideos));
            _Video.Content.Clear();
            _Medias = Database.getMediasFromFolder(Environment.GetFolderPath(Environment.SpecialFolder.MyVideos));
            foreach (Media elem in _Medias)
            {
                _Video.Content.Add(elem);
            }
            fill_listbox(_Medias);
        }

        private void listBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void AddPlaylist_Click(object sender, RoutedEventArgs e)
        {
            var dialog = new CreatePlaylist();
            if (dialog.ShowDialog() == true)
            {
                if (_Db.addPlaylist(dialog.ResponseText))
                    create_item_tree(dialog.ResponseText);
            }
        }

        private void create_item_tree(string playlistName)
        {
            var subItem = new TreeViewItem();
            subItem.MouseDoubleClick += SubItem_MouseDoubleClick;
            subItem.Header = playlistName;
            _Item.Items.Add(subItem);
        }

        private void SubItem_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            TreeViewItem obj = (TreeViewItem)TreeView.SelectedItem;
            string currentItem = obj.Header.ToString();
            _Medias = _Db.getMediasFromPlaylist(currentItem);
            change_playlist_name(currentItem);
            fill_listbox(_Medias);
        }

        private void addToplaylist_Click(object sender, RoutedEventArgs e)
        {
            var dialog = new SelectItem();
            List<string> playlist = _Db.getPlaylists();
            foreach (string elem in playlist)
            {
                dialog.listBox.Items.Add(elem);
            }
            if (dialog.ShowDialog() == true)
            {
                string itm = (string)dialog.listBox.SelectedItem;
                if (!string.IsNullOrEmpty(itm))
                {
                    OpenFileDialog file;
                    file = new OpenFileDialog();
                    file.AddExtension = true;
                    file.DefaultExt = "*.*";
                    file.Filter = "Media Files (*.*)|*.*";
                    file.ShowDialog();
                    _Db.addMediaToPlaylist(itm, file.FileName);
                }
            }
        }

        private void remove_playlist_Click(object sender, RoutedEventArgs e)
        {
            var dialog = new SelectItem();
            List<string> playlist = _Db.getPlaylists();
            foreach (string elem in playlist)
            {
                dialog.listBox.Items.Add(elem);
            }
            if (dialog.ShowDialog() == true)
            {
                string itm = (string)dialog.listBox.SelectedItem;
                _Db.removePlaylist(itm);
                _Item.Items.Clear();
                playlist = _Db.getPlaylists();
                foreach (string elem in playlist)
                {
                    create_item_tree(elem);
                }
                fill_listbox(_Current.Content);
            }
        }

        private void removeFromPlaylist_Click(object sender, RoutedEventArgs e)
        {
            String pl = null;
            String media = null;
            var dialog = new SelectItem();
            List<string> playlist = _Db.getPlaylists();

            foreach (string elem in playlist)
            {
                dialog.listBox.Items.Add(elem);
            }
            if (dialog.ShowDialog() == true)
            {
                pl = (string)dialog.listBox.SelectedItem;
                if (!string.IsNullOrEmpty(pl))
                {
                    dialog = new SelectItem();
                    List<Media> playlistMed = _Db.getMediasFromPlaylist(pl);
                    foreach (Media elem in playlistMed)
                    {
                        dialog.listBox.Items.Add(elem.Path);
                    }
                    if (dialog.ShowDialog() == true)
                    {
                        media = (string)dialog.listBox.SelectedItem;
                        _Db.removeMediaFromPlaylist(pl, media);
                    }
                }
            }
            
        }

        private void listView_click(object sender, RoutedEventArgs e)
        {
            GridViewColumnHeader headerClicked =
            e.OriginalSource as GridViewColumnHeader;
            if (headerClicked.Column != null)
            {
                string column = headerClicked.Column.Header.ToString();
                fill_listbox(_HrDir.sort(column, _Medias));
            }
        }

        private void change_folder_name(string folder)
        {
            _currentFolderName = folder;
            _currentPlaylistName = null;
        }

        private void change_playlist_name(string playlist)
        {
            _currentFolderName = null;
            _currentPlaylistName = playlist;
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
           if (_currentPlaylistName != null)
                _Medias = Filter.FilterMediaPlaylist(_Db, _currentPlaylistName, textBox.Text);
            else if (_currentFolderName != null)
                _Medias = Filter.FilterMediaFolder(_currentFolderName, textBox.Text);
            else if (_currentFolderName == null && _currentPlaylistName == null)
            {
                _Medias = Filter.FilterMediaList(_Current.Content, textBox.Text);
                if (string.IsNullOrEmpty(textBox.Text))
                    _Medias = new List<Media>(_Current.Content);
            }
            fill_listbox(_Medias);
        }
    }
}
