﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Newtonsoft.Json.Serialization;

namespace Adaptive.Schema.Net
{

    /// <summary>
    /// ShowCard defines an inline AdaptiveCard which is shown to the user when it is clicked.
    /// </summary>
    public class ShowCardAction : ActionBase
    {
        public ShowCardAction()
        {

        }

        /// <summary>
        /// Card to show when the action is invoked
        /// </summary>
        [JsonRequired]
        public AdaptiveCard Card { get; set; }
    }
}
