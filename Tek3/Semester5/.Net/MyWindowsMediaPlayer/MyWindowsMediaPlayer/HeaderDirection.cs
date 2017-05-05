using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyWindowsMediaPlayer
{
    class HeaderDirection
    {
        private bool _titre;
        private bool _album;
        private bool _artiste;
        private List<Media> _toSort;
        public string ALBUM = "Album";
        public string TITRE = "Title";
        public string ARTISTE = "Artiste";

        public bool Titre
        {
            get; set;
        }
        public bool Album
        {
            get; set;
        }
        public bool Artiste
        {
            get; set;
        }

        public HeaderDirection()
        {
        }

        public List<Media> sort(string Header, List<Media> toSort)
        {
            _toSort = toSort;
            if (Header == ALBUM)
            {
                if (_album)
                    _toSort = _toSort.OrderBy(o => o.Album).ToList();
                else
                    _toSort = _toSort.OrderByDescending(o => o.Album).ToList();
                _album = toggle(_album);
            }
            else if (Header == TITRE)
            {
                if (_titre)
                    _toSort = _toSort.OrderBy(o => o.Title).ToList();
                else
                    _toSort = _toSort.OrderByDescending(o => o.Title).ToList();
                _titre = toggle(_titre);
            }
            else if (Header == ARTISTE)
            {
                if (_artiste)
                    _toSort = _toSort.OrderBy(o => o.Artist).ToList();
                else
                    _toSort = _toSort.OrderByDescending(o => o.Artist).ToList();
                _artiste = toggle(_artiste);
            }
            return _toSort;
        }

        public bool toggle(bool toggle)
        {
            if (toggle)
                return toggle = false;
            return toggle = true;
        }
    }
}
