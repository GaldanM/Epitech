using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyWindowsMediaPlayer
{
    class PlaylistElem
    {
        private bool _state;
        private bool _isPlaying;
        private List<Media> _content;
        private string _name;

        public PlaylistElem(string name)
        {
            _state = false;
            _isPlaying = false;
            _content = new List<Media>();
        }

        public bool State
        {
            set { _state = value; }
            get { return _state; }
        }

        public bool IsPlaying
        {
            set { _isPlaying = value; }
            get { return _isPlaying; }
        }

        public string Name
        {
            set { _name = value; }
            get { return _name; }
        }

        public List<Media> Content
        {
            set { _content = value; }
            get { return _content; }

        }
    }
}
