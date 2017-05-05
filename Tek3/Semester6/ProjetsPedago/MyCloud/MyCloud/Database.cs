using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace MyCloud
{
    class Database
    {
        private String _Path = @"Accounts.xml";
        private XDocument _XmlDoc = null;
        private XElement _DropBox = null;
        private XElement _Drive = null;

        public Database()
        {
            XElement accs;

            try { _XmlDoc = XDocument.Load(_Path); }
            catch (Exception)
            {
                _XmlDoc = new XDocument(
                            new XDeclaration("1.0", "UTF-16", null), 
                            new XElement("Accounts",
                                new XElement("DropBox"),
                                new XElement("GoogleDrive")));
                _XmlDoc.Save(_Path);
            }

            if ((accs = _XmlDoc.Element("Accounts")) == null)
            {
                _XmlDoc.Add(new XElement("Accounts"));
                accs = _XmlDoc.Element("Accounts");
                _XmlDoc.Save(_Path);
            }
            if ((_DropBox = _XmlDoc.Element("Accounts").Element("DropBox")) == null)
            {
                accs.Add(new XElement("DropBox"));
                _DropBox = _XmlDoc.Element("Accounts").Element("DropBox");
                _XmlDoc.Save(_Path);
            }
            if ((_Drive = _XmlDoc.Element("Accounts").Element("GoogleDrive")) == null)
            {
                accs.Add(new XElement("GoogleDrive"));
                _Drive = _XmlDoc.Element("Accounts").Element("GoogleDrive");
                _XmlDoc.Save(_Path);
            }
        }

        public bool addDropBoxAccount(String token, String email)
        {
            var accounts =  from accs in _DropBox.Elements("Account")
                            where (String)accs.Attribute("Email") == email
                            select accs;

            if (!accounts.Any())
            {
                _DropBox.Add(new XElement("Account", new XAttribute("Token", token), new XAttribute("Email", email)));
                _XmlDoc.Save(_Path);
            }
            else
                return (false);
            return (true);
        }

        public List<Account> getDropBoxAccounts()
        {
            List<Account> list = new List<Account>();

            var accs = from acc in _DropBox.Elements("Account")
                            select acc;

            foreach (XElement elem in accs)
            {
                Account acc = new Account(elem.Attribute("Token").Value, elem.Attribute("Email").Value);
                list.Add(acc);
            }
            return (list);
        }
    }
}
