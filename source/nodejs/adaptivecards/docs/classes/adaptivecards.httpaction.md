[Adaptive Cards Javascript SDK](../README.md) / [adaptivecards](../modules/adaptivecards.md) / HttpAction

# Class: HttpAction

[adaptivecards](../modules/adaptivecards.md).HttpAction

## Hierarchy

* [*Action*](card_elements.action.md)

  ↳ **HttpAction**

## Table of contents

### Constructors

- [constructor](adaptivecards.httpaction.md#constructor)

### Properties

- [\_parent](adaptivecards.httpaction.md#_parent)
- [\_renderedElement](adaptivecards.httpaction.md#_renderedelement)
- [accessibleTitle](adaptivecards.httpaction.md#accessibletitle)
- [expanded](adaptivecards.httpaction.md#expanded)
- [headers](adaptivecards.httpaction.md#headers)
- [iconUrl](adaptivecards.httpaction.md#iconurl)
- [id](adaptivecards.httpaction.md#id)
- [maxVersion](adaptivecards.httpaction.md#maxversion)
- [method](adaptivecards.httpaction.md#method)
- [onExecute](adaptivecards.httpaction.md#onexecute)
- [onPreProcessPropertyValue](adaptivecards.httpaction.md#onpreprocesspropertyvalue)
- [style](adaptivecards.httpaction.md#style)
- [title](adaptivecards.httpaction.md#title)
- [JsonTypeName](adaptivecards.httpaction.md#jsontypename)
- [bodyProperty](adaptivecards.httpaction.md#bodyproperty)
- [defaultMaxVersion](adaptivecards.httpaction.md#defaultmaxversion)
- [headersProperty](adaptivecards.httpaction.md#headersproperty)
- [iconUrlProperty](adaptivecards.httpaction.md#iconurlproperty)
- [idProperty](adaptivecards.httpaction.md#idproperty)
- [ignoreInputValidationProperty](adaptivecards.httpaction.md#ignoreinputvalidationproperty)
- [methodProperty](adaptivecards.httpaction.md#methodproperty)
- [onRegisterCustomProperties](adaptivecards.httpaction.md#onregistercustomproperties)
- [requiresProperty](adaptivecards.httpaction.md#requiresproperty)
- [styleProperty](adaptivecards.httpaction.md#styleproperty)
- [titleProperty](adaptivecards.httpaction.md#titleproperty)
- [typeNameProperty](adaptivecards.httpaction.md#typenameproperty)
- [urlProperty](adaptivecards.httpaction.md#urlproperty)

### Accessors

- [body](adaptivecards.httpaction.md#body)
- [hostConfig](adaptivecards.httpaction.md#hostconfig)
- [ignoreInputValidation](adaptivecards.httpaction.md#ignoreinputvalidation)
- [isPrimary](adaptivecards.httpaction.md#isprimary)
- [parent](adaptivecards.httpaction.md#parent)
- [renderedElement](adaptivecards.httpaction.md#renderedelement)
- [requires](adaptivecards.httpaction.md#requires)
- [url](adaptivecards.httpaction.md#url)

### Methods

- [addCssClasses](adaptivecards.httpaction.md#addcssclasses)
- [execute](adaptivecards.httpaction.md#execute)
- [getActionById](adaptivecards.httpaction.md#getactionbyid)
- [getAllInputs](adaptivecards.httpaction.md#getallinputs)
- [getAriaRole](adaptivecards.httpaction.md#getariarole)
- [getCustomProperty](adaptivecards.httpaction.md#getcustomproperty)
- [getDefaultSerializationContext](adaptivecards.httpaction.md#getdefaultserializationcontext)
- [getHref](adaptivecards.httpaction.md#gethref)
- [getJsonTypeName](adaptivecards.httpaction.md#getjsontypename)
- [getReferencedInputs](adaptivecards.httpaction.md#getreferencedinputs)
- [getResourceInformation](adaptivecards.httpaction.md#getresourceinformation)
- [getRootObject](adaptivecards.httpaction.md#getrootobject)
- [getSchema](adaptivecards.httpaction.md#getschema)
- [getSchemaKey](adaptivecards.httpaction.md#getschemakey)
- [getValue](adaptivecards.httpaction.md#getvalue)
- [hasAllDefaultValues](adaptivecards.httpaction.md#hasalldefaultvalues)
- [hasDefaultValue](adaptivecards.httpaction.md#hasdefaultvalue)
- [internalGetReferencedInputs](adaptivecards.httpaction.md#internalgetreferencedinputs)
- [internalParse](adaptivecards.httpaction.md#internalparse)
- [internalPrepareForExecution](adaptivecards.httpaction.md#internalprepareforexecution)
- [internalToJSON](adaptivecards.httpaction.md#internaltojson)
- [internalValidateInputs](adaptivecards.httpaction.md#internalvalidateinputs)
- [internalValidateProperties](adaptivecards.httpaction.md#internalvalidateproperties)
- [parse](adaptivecards.httpaction.md#parse)
- [populateSchema](adaptivecards.httpaction.md#populateschema)
- [preProcessPropertyValue](adaptivecards.httpaction.md#preprocesspropertyvalue)
- [prepareForExecution](adaptivecards.httpaction.md#prepareforexecution)
- [raiseExecuteActionEvent](adaptivecards.httpaction.md#raiseexecuteactionevent)
- [remove](adaptivecards.httpaction.md#remove)
- [render](adaptivecards.httpaction.md#render)
- [resetDefaultValues](adaptivecards.httpaction.md#resetdefaultvalues)
- [setCustomProperty](adaptivecards.httpaction.md#setcustomproperty)
- [setParent](adaptivecards.httpaction.md#setparent)
- [setShouldFallback](adaptivecards.httpaction.md#setshouldfallback)
- [setValue](adaptivecards.httpaction.md#setvalue)
- [shouldFallback](adaptivecards.httpaction.md#shouldfallback)
- [shouldSerialize](adaptivecards.httpaction.md#shouldserialize)
- [toJSON](adaptivecards.httpaction.md#tojson)
- [updateActionButtonCssStyle](adaptivecards.httpaction.md#updateactionbuttoncssstyle)
- [validateInputs](adaptivecards.httpaction.md#validateinputs)
- [validateProperties](adaptivecards.httpaction.md#validateproperties)

## Constructors

### constructor

\+ **new HttpAction**(): [*HttpAction*](card_elements.httpaction.md)

**Returns:** [*HttpAction*](card_elements.httpaction.md)

Inherited from: [Action](card_elements.action.md)

Defined in: [serialization.ts:898](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L898)

## Properties

### \_parent

• `Protected` `Optional` **\_parent**: *undefined* \| [*CardObject*](card_object.cardobject.md)

Inherited from: [Action](card_elements.action.md).[_parent](card_elements.action.md#_parent)

Defined in: [card-object.ts:64](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L64)

___

### \_renderedElement

• `Protected` `Optional` **\_renderedElement**: *undefined* \| HTMLElement

Inherited from: [Action](card_elements.action.md).[_renderedElement](card_elements.action.md#_renderedelement)

Defined in: [card-object.ts:65](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L65)

___

### accessibleTitle

• `Optional` **accessibleTitle**: *undefined* \| *string*

Inherited from: [Action](card_elements.action.md).[accessibleTitle](card_elements.action.md#accessibletitle)

Defined in: [card-elements.ts:3789](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3789)

___

### expanded

• `Optional` **expanded**: *undefined* \| *boolean*

Inherited from: [Action](card_elements.action.md).[expanded](card_elements.action.md#expanded)

Defined in: [card-elements.ts:3790](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3790)

___

### headers

• **headers**: [*HttpHeader*](card_elements.httpheader.md)[]

Defined in: [card-elements.ts:4286](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4286)

___

### iconUrl

• `Optional` **iconUrl**: *undefined* \| *string*

Inherited from: [Action](card_elements.action.md).[iconUrl](card_elements.action.md#iconurl)

Defined in: [card-elements.ts:3736](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3736)

___

### id

• `Optional` **id**: *undefined* \| *string*

Inherited from: [Action](card_elements.action.md).[id](card_elements.action.md#id)

Defined in: [card-object.ts:53](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L53)

___

### maxVersion

• **maxVersion**: [*Version*](serialization.version.md)

Inherited from: [Action](card_elements.action.md).[maxVersion](card_elements.action.md#maxversion)

Defined in: [serialization.ts:898](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L898)

___

### method

• `Optional` **method**: *undefined* \| *string*

Defined in: [card-elements.ts:4283](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4283)

___

### onExecute

• **onExecute**: (`sender`: [*Action*](card_elements.action.md)) => *void*

#### Type declaration:

▸ (`sender`: [*Action*](card_elements.action.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`sender` | [*Action*](card_elements.action.md) |

**Returns:** *void*

Defined in: [card-elements.ts:3792](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3792)

Inherited from: [Action](card_elements.action.md).[onExecute](card_elements.action.md#onexecute)

Defined in: [card-elements.ts:3792](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3792)

___

### onPreProcessPropertyValue

• `Optional` **onPreProcessPropertyValue**: *undefined* \| (`sender`: [*CardObject*](card_object.cardobject.md), `property`: [*PropertyDefinition*](serialization.propertydefinition.md), `value`: *any*) => *any*

Inherited from: [Action](card_elements.action.md).[onPreProcessPropertyValue](card_elements.action.md#onpreprocesspropertyvalue)

Defined in: [card-object.ts:67](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L67)

___

### style

• **style**: *string*

Inherited from: [Action](card_elements.action.md).[style](card_elements.action.md#style)

Defined in: [card-elements.ts:3739](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3739)

___

### title

• `Optional` **title**: *undefined* \| *string*

Inherited from: [Action](card_elements.action.md).[title](card_elements.action.md#title)

Defined in: [card-elements.ts:3733](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3733)

___

### JsonTypeName

▪ `Readonly` `Static` **JsonTypeName**: *Action.Http*= "Action.Http"

Defined in: [card-elements.ts:4295](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4295)

___

### bodyProperty

▪ `Readonly` `Static` **bodyProperty**: *StringWithSubstitutionProperty*

Defined in: [card-elements.ts:4271](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4271)

___

### defaultMaxVersion

▪ `Static` **defaultMaxVersion**: [*Version*](serialization.version.md)

Inherited from: [Action](card_elements.action.md).[defaultMaxVersion](card_elements.action.md#defaultmaxversion)

Defined in: [serialization.ts:775](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L775)

___

### headersProperty

▪ `Readonly` `Static` **headersProperty**: [*SerializableObjectCollectionProperty*](serialization.serializableobjectcollectionproperty.md)

Defined in: [card-elements.ts:4273](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4273)

___

### iconUrlProperty

▪ `Readonly` `Static` **iconUrlProperty**: [*StringProperty*](serialization.stringproperty.md)

Inherited from: [Action](card_elements.action.md).[iconUrlProperty](card_elements.action.md#iconurlproperty)

Defined in: [card-elements.ts:3721](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3721)

___

### idProperty

▪ `Readonly` `Static` **idProperty**: [*StringProperty*](serialization.stringproperty.md)

Inherited from: [Action](card_elements.action.md).[idProperty](card_elements.action.md#idproperty)

Defined in: [card-object.ts:41](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L41)

___

### ignoreInputValidationProperty

▪ `Readonly` `Static` **ignoreInputValidationProperty**: [*BoolProperty*](serialization.boolproperty.md)

Defined in: [card-elements.ts:4274](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4274)

___

### methodProperty

▪ `Readonly` `Static` **methodProperty**: [*StringProperty*](serialization.stringproperty.md)

Defined in: [card-elements.ts:4272](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4272)

___

### onRegisterCustomProperties

▪ `Optional` `Static` **onRegisterCustomProperties**: *undefined* \| (`sender`: [*SerializableObject*](serialization.serializableobject.md), `schema`: [*SerializableObjectSchema*](serialization.serializableobjectschema.md)) => *void*

Inherited from: [Action](card_elements.action.md).[onRegisterCustomProperties](card_elements.action.md#onregistercustomproperties)

Defined in: [serialization.ts:774](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L774)

___

### requiresProperty

▪ `Readonly` `Static` **requiresProperty**: [*SerializableObjectProperty*](serialization.serializableobjectproperty.md)

Inherited from: [Action](card_elements.action.md).[requiresProperty](card_elements.action.md#requiresproperty)

Defined in: [card-object.ts:42](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L42)

___

### styleProperty

▪ `Readonly` `Static` **styleProperty**: [*ValueSetProperty*](serialization.valuesetproperty.md)

Inherited from: [Action](card_elements.action.md).[styleProperty](card_elements.action.md#styleproperty)

Defined in: [card-elements.ts:3722](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3722)

___

### titleProperty

▪ `Readonly` `Static` **titleProperty**: [*StringProperty*](serialization.stringproperty.md)

Inherited from: [Action](card_elements.action.md).[titleProperty](card_elements.action.md#titleproperty)

Defined in: [card-elements.ts:3720](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3720)

___

### typeNameProperty

▪ `Readonly` `Static` **typeNameProperty**: [*StringProperty*](serialization.stringproperty.md)

Inherited from: [Action](card_elements.action.md).[typeNameProperty](card_elements.action.md#typenameproperty)

Defined in: [card-object.ts:32](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L32)

___

### urlProperty

▪ `Readonly` `Static` **urlProperty**: *StringWithSubstitutionProperty*

Defined in: [card-elements.ts:4270](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4270)

## Accessors

### body

• get **body**(): *undefined* \| *string*

**Returns:** *undefined* \| *string*

Defined in: [card-elements.ts:4372](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4372)

• set **body**(`value`: *undefined* \| *string*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *undefined* \| *string* |

**Returns:** *void*

Defined in: [card-elements.ts:4376](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4376)

___

### hostConfig

• get **hostConfig**(): [*HostConfig*](host_config.hostconfig.md)

**Returns:** [*HostConfig*](host_config.hostconfig.md)

Defined in: [card-elements.ts:3956](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3956)

___

### ignoreInputValidation

• get **ignoreInputValidation**(): *boolean*

**Returns:** *boolean*

Defined in: [card-elements.ts:4356](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4356)

• set **ignoreInputValidation**(`value`: *boolean*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *boolean* |

**Returns:** *void*

Defined in: [card-elements.ts:4360](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4360)

___

### isPrimary

• get **isPrimary**(): *boolean*

**Returns:** *boolean*

Defined in: [card-elements.ts:3941](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3941)

• set **isPrimary**(`value`: *boolean*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *boolean* |

**Returns:** *void*

Defined in: [card-elements.ts:3945](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3945)

___

### parent

• get **parent**(): *undefined* \| [*CardElement*](card_elements.cardelement.md)

**Returns:** *undefined* \| [*CardElement*](card_elements.cardelement.md)

Defined in: [card-elements.ts:3960](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3960)

___

### renderedElement

• get **renderedElement**(): *undefined* \| HTMLElement

**Returns:** *undefined* \| HTMLElement

Defined in: [card-object.ts:143](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L143)

___

### requires

• get **requires**(): [*HostCapabilities*](host_capabilities.hostcapabilities.md)

**Returns:** [*HostCapabilities*](host_capabilities.hostcapabilities.md)

Defined in: [card-object.ts:56](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L56)

___

### url

• get **url**(): *undefined* \| *string*

**Returns:** *undefined* \| *string*

Defined in: [card-elements.ts:4364](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4364)

• set **url**(`value`: *undefined* \| *string*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *undefined* \| *string* |

**Returns:** *void*

Defined in: [card-elements.ts:4368](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4368)

## Methods

### addCssClasses

▸ `Protected`**addCssClasses**(`element`: HTMLElement): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`element` | HTMLElement |

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3749](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3749)

___

### execute

▸ **execute**(): *void*

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3885](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3885)

___

### getActionById

▸ **getActionById**(`id`: *string*): *undefined* \| [*Action*](card_elements.action.md)

#### Parameters:

Name | Type |
:------ | :------ |
`id` | *string* |

**Returns:** *undefined* \| [*Action*](card_elements.action.md)

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3924](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3924)

___

### getAllInputs

▸ **getAllInputs**(`processActions?`: *boolean*): [*Input*](card_elements.input.md)[]

#### Parameters:

Name | Type | Default value |
:------ | :------ | :------ |
`processActions` | *boolean* | true |

**Returns:** [*Input*](card_elements.input.md)[]

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3916](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3916)

___

### getAriaRole

▸ **getAriaRole**(): *string*

**Returns:** *string*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3798](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3798)

___

### getCustomProperty

▸ **getCustomProperty**(`name`: *string*): *any*

#### Parameters:

Name | Type |
:------ | :------ |
`name` | *string* |

**Returns:** *any*

Inherited from: [Action](card_elements.action.md)

Defined in: [serialization.ts:985](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L985)

___

### getDefaultSerializationContext

▸ `Protected`**getDefaultSerializationContext**(): [*BaseSerializationContext*](serialization.baseserializationcontext.md)

**Returns:** [*BaseSerializationContext*](serialization.baseserializationcontext.md)

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3745](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3745)

___

### getHref

▸ **getHref**(): *undefined* \| *string*

**Returns:** *undefined* \| *string*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3794](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3794)

___

### getJsonTypeName

▸ **getJsonTypeName**(): *string*

**Returns:** *string*

Overrides: [Action](card_elements.action.md)

Defined in: [card-elements.ts:4330](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4330)

___

### getReferencedInputs

▸ **getReferencedInputs**(): *undefined* \| [*Dictionary*](../modules/shared.md#dictionary)<[*Input*](card_elements.input.md)\>

**Returns:** *undefined* \| [*Dictionary*](../modules/shared.md#dictionary)<[*Input*](card_elements.input.md)\>

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3928](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3928)

___

### getResourceInformation

▸ **getResourceInformation**(): [*IResourceInformation*](../interfaces/shared.iresourceinformation.md)[]

**Returns:** [*IResourceInformation*](../interfaces/shared.iresourceinformation.md)[]

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3920](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3920)

___

### getRootObject

▸ **getRootObject**(): [*CardObject*](card_object.cardobject.md)

**Returns:** [*CardObject*](card_object.cardobject.md)

Inherited from: [Action](card_elements.action.md)

Defined in: [card-object.ts:103](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L103)

___

### getSchema

▸ **getSchema**(): [*SerializableObjectSchema*](serialization.serializableobjectschema.md)

**Returns:** [*SerializableObjectSchema*](serialization.serializableobjectschema.md)

Inherited from: [Action](card_elements.action.md)

Defined in: [serialization.ts:989](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L989)

___

### getSchemaKey

▸ `Protected`**getSchemaKey**(): *string*

**Returns:** *string*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-object.ts:48](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L48)

___

### getValue

▸ `Protected`**getValue**(`property`: [*PropertyDefinition*](serialization.propertydefinition.md)): *any*

#### Parameters:

Name | Type |
:------ | :------ |
`property` | [*PropertyDefinition*](serialization.propertydefinition.md) |

**Returns:** *any*

Inherited from: [Action](card_elements.action.md)

Defined in: [serialization.ts:826](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L826)

___

### hasAllDefaultValues

▸ **hasAllDefaultValues**(): *boolean*

**Returns:** *boolean*

Inherited from: [Action](card_elements.action.md)

Defined in: [serialization.ts:950](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L950)

___

### hasDefaultValue

▸ **hasDefaultValue**(`property`: [*PropertyDefinition*](serialization.propertydefinition.md)): *boolean*

#### Parameters:

Name | Type |
:------ | :------ |
`property` | [*PropertyDefinition*](serialization.propertydefinition.md) |

**Returns:** *boolean*

Inherited from: [Action](card_elements.action.md)

Defined in: [serialization.ts:946](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L946)

___

### internalGetReferencedInputs

▸ `Protected`**internalGetReferencedInputs**(): [*Dictionary*](../modules/shared.md#dictionary)<[*Input*](card_elements.input.md)\>

**Returns:** [*Dictionary*](../modules/shared.md#dictionary)<[*Input*](card_elements.input.md)\>

Overrides: [Action](card_elements.action.md)

Defined in: [card-elements.ts:4297](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4297)

___

### internalParse

▸ `Protected`**internalParse**(`source`: [*PropertyBag*](../modules/serialization.md#propertybag), `context`: [*BaseSerializationContext*](serialization.baseserializationcontext.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`source` | [*PropertyBag*](../modules/serialization.md#propertybag) |
`context` | [*BaseSerializationContext*](serialization.baseserializationcontext.md) |

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [serialization.ts:839](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L839)

___

### internalPrepareForExecution

▸ `Protected`**internalPrepareForExecution**(`inputs`: *undefined* \| [*Dictionary*](../modules/shared.md#dictionary)<[*Input*](card_elements.input.md)\>): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`inputs` | *undefined* \| [*Dictionary*](../modules/shared.md#dictionary)<[*Input*](card_elements.input.md)\> |

**Returns:** *void*

Overrides: [Action](card_elements.action.md)

Defined in: [card-elements.ts:4312](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4312)

___

### internalToJSON

▸ `Protected`**internalToJSON**(`target`: [*PropertyBag*](../modules/serialization.md#propertybag), `context`: [*BaseSerializationContext*](serialization.baseserializationcontext.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`target` | [*PropertyBag*](../modules/serialization.md#propertybag) |
`context` | [*BaseSerializationContext*](serialization.baseserializationcontext.md) |

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [serialization.ts:876](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L876)

___

### internalValidateInputs

▸ `Protected`**internalValidateInputs**(`referencedInputs`: *undefined* \| [*Dictionary*](../modules/shared.md#dictionary)<[*Input*](card_elements.input.md)\>): [*Input*](card_elements.input.md)[]

#### Parameters:

Name | Type |
:------ | :------ |
`referencedInputs` | *undefined* \| [*Dictionary*](../modules/shared.md#dictionary)<[*Input*](card_elements.input.md)\> |

**Returns:** [*Input*](card_elements.input.md)[]

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3761](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3761)

___

### internalValidateProperties

▸ **internalValidateProperties**(`context`: [*ValidationResults*](card_object.validationresults.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`context` | [*ValidationResults*](card_object.validationresults.md) |

**Returns:** *void*

Overrides: [Action](card_elements.action.md)

Defined in: [card-elements.ts:4334](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L4334)

___

### parse

▸ **parse**(`source`: *any*, `context?`: [*SerializationContext*](card_elements.serializationcontext.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`source` | *any* |
`context?` | [*SerializationContext*](card_elements.serializationcontext.md) |

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3806](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3806)

___

### populateSchema

▸ `Protected`**populateSchema**(`schema`: [*SerializableObjectSchema*](serialization.serializableobjectschema.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`schema` | [*SerializableObjectSchema*](serialization.serializableobjectschema.md) |

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [serialization.ts:788](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L788)

___

### preProcessPropertyValue

▸ **preProcessPropertyValue**(`property`: [*PropertyDefinition*](serialization.propertydefinition.md), `propertyValue?`: *any*): *any*

#### Parameters:

Name | Type |
:------ | :------ |
`property` | [*PropertyDefinition*](serialization.propertydefinition.md) |
`propertyValue?` | *any* |

**Returns:** *any*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-object.ts:73](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L73)

___

### prepareForExecution

▸ **prepareForExecution**(): *boolean*

**Returns:** *boolean*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3893](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3893)

___

### raiseExecuteActionEvent

▸ `Protected`**raiseExecuteActionEvent**(): *void*

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3781](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3781)

___

### remove

▸ **remove**(): *boolean*

**Returns:** *boolean*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3908](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3908)

___

### render

▸ **render**(`baseCssClass?`: *string*): *void*

#### Parameters:

Name | Type | Default value |
:------ | :------ | :------ |
`baseCssClass` | *string* | "ac-pushButton" |

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3810](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3810)

___

### resetDefaultValues

▸ **resetDefaultValues**(): *void*

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [serialization.ts:964](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L964)

___

### setCustomProperty

▸ **setCustomProperty**(`name`: *string*, `value`: *any*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`name` | *string* |
`value` | *any* |

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [serialization.ts:974](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L974)

___

### setParent

▸ **setParent**(`value`: *undefined* \| [*CardObject*](card_object.cardobject.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *undefined* \| [*CardObject*](card_object.cardobject.md) |

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-object.ts:91](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L91)

___

### setShouldFallback

▸ **setShouldFallback**(`value`: *boolean*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *boolean* |

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-object.ts:95](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L95)

___

### setValue

▸ `Protected`**setValue**(`property`: [*PropertyDefinition*](serialization.propertydefinition.md), `value`: *any*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`property` | [*PropertyDefinition*](serialization.propertydefinition.md) |
`value` | *any* |

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [serialization.ts:830](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L830)

___

### shouldFallback

▸ **shouldFallback**(): *boolean*

**Returns:** *boolean*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-object.ts:99](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L99)

___

### shouldSerialize

▸ `Protected`**shouldSerialize**(`context`: [*SerializationContext*](card_elements.serializationcontext.md)): *boolean*

#### Parameters:

Name | Type |
:------ | :------ |
`context` | [*SerializationContext*](card_elements.serializationcontext.md) |

**Returns:** *boolean*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3777](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3777)

___

### toJSON

▸ **toJSON**(`context?`: [*BaseSerializationContext*](serialization.baseserializationcontext.md)): *undefined* \| [*PropertyBag*](../modules/serialization.md#propertybag)

#### Parameters:

Name | Type |
:------ | :------ |
`context?` | [*BaseSerializationContext*](serialization.baseserializationcontext.md) |

**Returns:** *undefined* \| [*PropertyBag*](../modules/serialization.md#propertybag)

Inherited from: [Action](card_elements.action.md)

Defined in: [serialization.ts:916](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L916)

___

### updateActionButtonCssStyle

▸ **updateActionButtonCssStyle**(`actionButtonElement`: HTMLElement, `buttonState?`: ActionButtonState): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`actionButtonElement` | HTMLElement |
`buttonState` | ActionButtonState |

**Returns:** *void*

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3802](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3802)

___

### validateInputs

▸ **validateInputs**(): [*Input*](card_elements.input.md)[]

Validates the inputs associated with this action.

**Returns:** [*Input*](card_elements.input.md)[]

A list of inputs that failed validation, or an empty array if no input failed validation.

Inherited from: [Action](card_elements.action.md)

Defined in: [card-elements.ts:3937](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L3937)

___

### validateProperties

▸ **validateProperties**(): [*ValidationResults*](card_object.validationresults.md)

**Returns:** [*ValidationResults*](card_object.validationresults.md)

Inherited from: [Action](card_elements.action.md)

Defined in: [card-object.ts:131](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L131)
