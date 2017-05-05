using System;
using System.Collections.Generic;

namespace MyWindowsMediaPlayer
{
    class Filter
    {
        public static List<Media> FilterMediaPlaylist(Database db, String playlistName, String filter)
        {
            List<Media> list = db.getMediasFromPlaylist(playlistName);
            List<Media> ret = new List<Media>();

            foreach (Media elem in list)
            {
                if (elem.Title.IndexOf(filter, StringComparison.OrdinalIgnoreCase) >= 0
                    || (elem.Artist != null && elem.Artist.IndexOf(filter, StringComparison.OrdinalIgnoreCase) >= 0)
                    || (elem.Album != null && elem.Album.IndexOf(filter, StringComparison.OrdinalIgnoreCase) >= 0))
                    ret.Add(elem);
            }
            return (ret);
        }

        public static List<Media> FilterMediaFolder(String folderPath, String filter)
        {
            List<Media> list = Database.getMediasFromFolder(folderPath);
            List<Media> ret = new List<Media>();

            foreach (Media elem in list)
            {
                if (elem.Title.IndexOf(filter, StringComparison.OrdinalIgnoreCase) >= 0
                     || (elem.Artist != null && elem.Artist.IndexOf(filter, StringComparison.OrdinalIgnoreCase) >= 0)
                     || (elem.Album != null && elem.Album.IndexOf(filter, StringComparison.OrdinalIgnoreCase) >= 0))
                    ret.Add(elem);
            }

            return (ret);
        }

        public static List<Media> FilterMediaList(List<Media> list, String filter)
        {
            List<Media> ret = new List<Media>();

            foreach(Media elem in list)
            {
                if (elem.Title.IndexOf(filter, StringComparison.OrdinalIgnoreCase) >= 0
                    || (elem.Artist != null && elem.Artist.IndexOf(filter, StringComparison.OrdinalIgnoreCase) >= 0)
                    || (elem.Album != null && elem.Album.IndexOf(filter, StringComparison.OrdinalIgnoreCase) >= 0))
                    ret.Add(elem);
            }
            return (ret);
        }
    }
}
