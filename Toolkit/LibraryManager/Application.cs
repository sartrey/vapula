﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Vapula.Toolkit;

namespace Vapula.ComManager
{
    public class AppData
    {
        private static AppConfig _Config = null;
        public static AppConfig Config
        {
            get
            {
                if (_Config == null) _Config = new AppConfig();
                return _Config;
            }
        }
    }
}
