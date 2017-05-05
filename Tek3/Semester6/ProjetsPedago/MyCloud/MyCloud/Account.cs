using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyCloud
{
    class Account
    {
        private String _Token;
        private String _Email;

        public Account(String token, String email)
        {
            _Token = token;
            _Email = email;
        }

        public String Token
        {
            set { _Token = value; }
            get { return _Token; }
        }
        public String Email
        {
            set { _Email = value; }
            get { return _Email; }
        }
    }
}
