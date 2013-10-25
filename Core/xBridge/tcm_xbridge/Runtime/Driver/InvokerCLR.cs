﻿using System;
using System.Collections.Generic;
using System.Reflection;
using System.Windows.Forms;
using TCM.Helper;

namespace TCM.Runtime
{
    public class InvokerCLR : Invoker
    {
        private static List<InvokerCLR> _Invokers
            = new List<InvokerCLR>();

        public static InvokerCLR GetInvoker(IntPtr handle)
        {
            foreach (InvokerCLR inv in _Invokers)
                if (inv._Handle == handle) return inv;
            return null;
        }

        private LibraryCLR _Library = null;

        public InvokerCLR(IntPtr handle, LibraryCLR lib)
            : base(handle)
        {
            _Library = lib;
            _Invokers.Add(this);
        }

        public override void Dispose()
        {
            _Invokers.Remove(this);
            base.Dispose();
        }

        public int CallEntry()
        {
            Assembly assembly = _Library.Assembly;
            Type type = assembly.GetType(_Library.Id + ".Program");
            if (type == null) 
                return (int)ReturnCode.Error;
            try
            {
                object instance = Activator.CreateInstance(type);
                MethodInfo method = type.GetMethod("Run");
                ReturnCode rc = (ReturnCode)method.Invoke(instance,
                    new object[] { FunctionId, Envelope, Context });
                return (int)rc;
            }
            catch (Exception ex)
            {
                Base.Logger.WriteLog(LogType.Error, 
                    ex.Message, 
                    ex.Source, 
                    ex.StackTrace);
                return (int)ReturnCode.Error;
            }
        }
    }
}
