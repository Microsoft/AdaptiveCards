// TOOD: Can I pull this from the samples folder rather than copying it here?

export const defaultPayload: string = `

{
	"@type": "AdaptiveCard",
	"body": [
		{
		    "@type": "Container",
			"items": [
			    {
			        "@type": "TextBlock",
			        "text": "Card created: Publish Adaptive Card schema",
			        "textWeight": "bolder",
			        "textSize": "medium"
			    },
				{
					"@type": "ColumnGroup",
					"speak": "<s>Created by Miguel Garcia</s>",
					"items": [
						{
							"size": "auto",
							"items": [
                				{
                					"@type": "Image",
                					"url": "http://connectorsdemo.azurewebsites.net/images/MSC12_Oscar_002.jpg",
                					"size": "small",
                					"style": "person"
                				}
							]
						},
						{
							"size": "stretch",
							"items": [
							    {
							        "@type": "TextBlock",
							        "text": "**Miguel Garcia**",
							        "wrap": true
							    },
							    {
							        "@type": "TextBlock",
							        "text": "9/13/2016, 3:34pm",
							        "isSubtle": true,
							        "wrap": true
							    }
							]
						}
					]
				}
			]
		},
		{
		    "@type": "Container",
		    "items": [
			    {
			        "@type": "TextBlock",
					"speak": "",
			        "text": "Now that we have define the main rules and features of the format, we need to produce a schema and publish it to GitHub. The schema will be the starting point of our reference documentation.",
			        "wrap": true
			    },
				{
				    "@type": "FactGroup",
				    "items": [
				        { "name": "Board:", "value": "Adaptive Card", "speak":"" },
				        { "name": "List:", "value": "Backlog", "speak":"" },
				        { "name": "Assigned to:", "value": "David Claux" },
				        { "name": "Due date:", "value": "Not set", "speak":"" }
				    ]
				},
				{
				    "@type": "ActionGroup",
					"speak": "You can set the due date, add a comment or view more information.",
				    "items": [
                		{
                			"@type": "ActionCard",
                			"name": "Set due date",
                			"inputs": [
                				{
                					"@type": "DateInput",
                					"id": "dueDate",
                					"title": "Select a date"
                				}
                			],
                			"actions": [
                				{
                					"@type": "HttpPOST",
                					"name": "OK",
                					"target": "http://..."
                				}
                			]
                		},
                		{
                			"@type": "ActionCard",
                			"name": "Comment",
                			"inputs": [
                				{
                					"@type": "TextInput",
                					"id": "comment",
                					"isMultiline": true,
                					"title": "Enter your comment"
                				}
                			],
                			"actions": [
                				{
                					"@type": "HttpPOST",
                					"name": "OK",
                					"target": "http://..."
                				}
                			]
                		},
                		{
                			"@type": "OpenUri",
                			"name": "View",
                			"targets": [
                				{ "os": "default", "uri": "http://..." }
                			]
                		}
				    ]
				}
			]
		}
	]
}`;