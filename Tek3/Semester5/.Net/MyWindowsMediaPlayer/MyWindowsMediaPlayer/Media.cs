using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyWindowsMediaPlayer
{
    public class Media
    {
        private String      title;
        private String      artist;
        private String      album;
        private String      length;
        private DateTime    date;
        private String      size;
        private String      path;

        public String Title
        {
            get { return this.title; }
            set { this.title = value; }
        }

        public String Artist
        {
            get { return this.artist; }
            set { this.artist = value; }
        }
        public String Album
        {
            get { return this.album; }
            set { this.album = value; }
        }
        public String Length
        {
            get { return this.length; }
            set { this.length = value; }
        }
        public DateTime Date
        {
            get { return this.date; }
            set { this.date = value; }
        }
        public String Size
        {
            get { return this.size; }
            set { this.size = value; }
        }
        public String Path
        {
            get { return this.path; }
            set { this.path = value; }
        }
    }
}
