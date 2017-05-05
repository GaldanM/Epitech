using System;
using System.IO;
using System.Linq;
using System.Xml.Linq;
using System.Collections.Generic;

namespace MyWindowsMediaPlayer
{
    public class Database
    {
        private String PathDirectory = @"Playlists";
        private String PathPlaylists = @"Playlists\Playlists.xml";
        private XDocument XmlDoc = null;
        private XElement Playlists = null;

        public Database()
        {
            try { XmlDoc = XDocument.Load(PathPlaylists); }
            catch (Exception ex)
            {
                if (ex is DirectoryNotFoundException)
                    Directory.CreateDirectory(PathDirectory);
                XmlDoc = new XDocument(new XDeclaration("1.0", "UTF-16", null), new XElement("Playlists"));
                XmlDoc.Save(PathPlaylists);
            }
            Playlists = XmlDoc.Element("Playlists");
        }

        public List<String> getPlaylists()
        {
            List<String> list = new List<String>();

            var playlists = from play in Playlists.Elements("Playlist")
                            select play;

            foreach(XElement elem in playlists)
            {
                String name = elem.Attribute("PlaylistName").Value;
                if (!String.IsNullOrEmpty(name))
                    list.Add(name);
            }
            return (list);
        }

        public bool addPlaylist(String playlistName)
        {
            var playlists = from play in Playlists.Elements("Playlist")
                            where (String)play.Attribute("PlaylistName") == playlistName
                            select play;

            if (!playlists.Any())
            {
                Playlists.Add(new XElement("Playlist", new XAttribute("PlaylistName", playlistName)));
                XmlDoc.Save(PathPlaylists);
            }
            else
                return (false);
            return (true);
        }

        public bool removePlaylist(String playlistName)
        {
            var playlist = from play in Playlists.Elements("Playlist")
                           where (String)play.Attribute("PlaylistName") == playlistName
                           select play;

            if (playlist.Any())
            {
                playlist.FirstOrDefault().Remove();
                XmlDoc.Save(PathPlaylists);
            }
            else
                return (false);
            return (true);
        }

        public bool addMediaToPlaylist(String playlistName, String pathMedia)
        {
            var playlists = from playlist in Playlists.Elements("Playlist")
                            where (String)playlist.Attribute("PlaylistName") == playlistName
                            select playlist;

            if (playlists.Any())
            {
                var medias = from media in playlists.FirstOrDefault().Elements("Media")
                             where (String)media.Attribute("Path") == pathMedia
                             select media;

                if (!medias.Any())
                {
                    playlists.FirstOrDefault().Add(new XElement("Media", new XAttribute("Path", pathMedia)));
                    XmlDoc.Save(PathPlaylists);
                }
                else
                    return (false);
            }
            else
                return (false);
            return (true);
        }

        public bool removeMediaFromPlaylist(String playlistName, String pathMedia)
        {
            var playlists = from playlist in Playlists.Elements("Playlist")
                            where (String)playlist.Attribute("PlaylistName") == playlistName
                            select playlist;

            if (playlists.Any())
            {
                var medias = from media in playlists.FirstOrDefault().Elements("Media")
                             where (String)media.Attribute("Path") == pathMedia
                             select media;

                if (medias.Any())
                {
                    medias.FirstOrDefault().Remove();
                    XmlDoc.Save(PathPlaylists);
                }
                else
                    return (false);
            }
            else
                return (false);
            return (true);
        }

        public List<Media> getMediasFromPlaylist(String playlistName)
        {
            List<Media> list = new List<Media>();

            var playlists = from playlist in Playlists.Elements("Playlist")
                            where (String)playlist.Attribute("PlaylistName") == playlistName
                            select playlist;

            if (playlists.Any())
            {
                var medias = from media in playlists.FirstOrDefault().Elements("Media")
                             select media;

                foreach (XElement elem in medias)
                {
                    Media toAdd = getMedia(elem.Attribute("Path").Value);

                    if (toAdd.Path != null)
                        list.Add(toAdd);
                }
            }
            return (list);
        }

        public static List<Media> getMediasFromFolder(String pathFolder)
        {
            List<Media> list = new List<Media>();
            var medias = Directory.GetFiles(pathFolder).Where(p => Path.GetExtension(p) != ".ini");

            foreach (String media in medias)
            {
                Media toAdd = getMedia(media);

                if (toAdd.Path != null)
                    list.Add(toAdd);
            }
            return (list);
        }

        public static Media getMedia(String mediaPath)
        {
            FileInfo    info;
            TagLib.File fileTag;
            try
            {
                info = new FileInfo(mediaPath);
                fileTag = TagLib.File.Create(mediaPath);
            }
            catch(Exception)
            {
                return (new Media());
            }
            Media media = new Media();
            media.Title = info.Name;
            media.Artist = String.Join(";", fileTag.Tag.Performers);
            media.Album = fileTag.Tag.Album;
            media.Length = fileTag.Properties.Duration.ToString();
            if (media.Length.Contains("."))
                media.Length = media.Length.Remove(media.Length.LastIndexOf('.'));
            media.Date = info.CreationTime;
            media.Size = convertSize(info.Length);
            media.Path = mediaPath;

            return (media);
        }

        private static String convertSize(long length)
        {
            int i = 0;
            double size = length;
            String unit = "o";

            while (length > 1024)
            {
                length /= 1024;
                ++i;
            }
            switch (i)
            {
                case 1:
                    unit = "Ko";
                    break;
                case 2:
                    unit = "Mo";
                    break;
                case 3:
                    unit = "Go";
                    break;
                case 4:
                    unit = "To";
                    break;
            }
            return (length.ToString() + " " + unit);
        }
    }
}