﻿using System;
using System.Collections.Generic;
using System.Text;
using Xilium.CefGlue;

namespace TCM.xHost
{
    internal sealed class WebLifeSpanHandler : CefLifeSpanHandler
    {
        private readonly WebBrowser _core;

        public WebLifeSpanHandler(WebBrowser core)
        {
            _core = core;
        }

        protected override void OnAfterCreated(CefBrowser browser)
        {
            base.OnAfterCreated(browser);

            _core.OnCreated(browser);
        }

        protected override bool DoClose(CefBrowser browser)
        {
            // TODO: dispose core
            return false;
        }
    }
}