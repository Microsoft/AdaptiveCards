[Adaptive Cards Javascript SDK](../README.md) / [card-elements](../modules/card_elements.md) / ColumnSet

# Class: ColumnSet

[card-elements](../modules/card_elements.md).ColumnSet

## Hierarchy

* [*StylableCardElementContainer*](card_elements.stylablecardelementcontainer.md)

  ↳ **ColumnSet**

## Table of contents

### Constructors

- [constructor](card_elements.columnset.md#constructor)

### Properties

- [\_parent](card_elements.columnset.md#_parent)
- [\_renderedElement](card_elements.columnset.md#_renderedelement)
- [\_selectAction](card_elements.columnset.md#_selectaction)
- [allowVerticalOverflow](card_elements.columnset.md#allowverticaloverflow)
- [customCssSelector](card_elements.columnset.md#customcssselector)
- [height](card_elements.columnset.md#height)
- [horizontalAlignment](card_elements.columnset.md#horizontalalignment)
- [id](card_elements.columnset.md#id)
- [maxVersion](card_elements.columnset.md#maxversion)
- [minPixelHeight](card_elements.columnset.md#minpixelheight)
- [onPreProcessPropertyValue](card_elements.columnset.md#onpreprocesspropertyvalue)
- [separator](card_elements.columnset.md#separator)
- [spacing](card_elements.columnset.md#spacing)
- [bleedProperty](card_elements.columnset.md#bleedproperty)
- [defaultMaxVersion](card_elements.columnset.md#defaultmaxversion)
- [heightProperty](card_elements.columnset.md#heightproperty)
- [horizontalAlignmentProperty](card_elements.columnset.md#horizontalalignmentproperty)
- [idProperty](card_elements.columnset.md#idproperty)
- [isVisibleProperty](card_elements.columnset.md#isvisibleproperty)
- [langProperty](card_elements.columnset.md#langproperty)
- [minHeightProperty](card_elements.columnset.md#minheightproperty)
- [onRegisterCustomProperties](card_elements.columnset.md#onregistercustomproperties)
- [requiresProperty](card_elements.columnset.md#requiresproperty)
- [selectActionProperty](card_elements.columnset.md#selectactionproperty)
- [separatorProperty](card_elements.columnset.md#separatorproperty)
- [spacingProperty](card_elements.columnset.md#spacingproperty)
- [styleProperty](card_elements.columnset.md#styleproperty)
- [typeNameProperty](card_elements.columnset.md#typenameproperty)

### Accessors

- [allowCustomPadding](card_elements.columnset.md#allowcustompadding)
- [allowCustomStyle](card_elements.columnset.md#allowcustomstyle)
- [bleed](card_elements.columnset.md#bleed)
- [defaultStyle](card_elements.columnset.md#defaultstyle)
- [hasExplicitStyle](card_elements.columnset.md#hasexplicitstyle)
- [hasVisibleSeparator](card_elements.columnset.md#hasvisibleseparator)
- [hostConfig](card_elements.columnset.md#hostconfig)
- [index](card_elements.columnset.md#index)
- [isInline](card_elements.columnset.md#isinline)
- [isInteractive](card_elements.columnset.md#isinteractive)
- [isSelectable](card_elements.columnset.md#isselectable)
- [isStandalone](card_elements.columnset.md#isstandalone)
- [isVisible](card_elements.columnset.md#isvisible)
- [lang](card_elements.columnset.md#lang)
- [padding](card_elements.columnset.md#padding)
- [parent](card_elements.columnset.md#parent)
- [renderedActionCount](card_elements.columnset.md#renderedactioncount)
- [renderedElement](card_elements.columnset.md#renderedelement)
- [requires](card_elements.columnset.md#requires)
- [selectAction](card_elements.columnset.md#selectaction)
- [separatorElement](card_elements.columnset.md#separatorelement)
- [separatorOrientation](card_elements.columnset.md#separatororientation)
- [style](card_elements.columnset.md#style)
- [useDefaultSizing](card_elements.columnset.md#usedefaultsizing)

### Methods

- [addColumn](card_elements.columnset.md#addcolumn)
- [adjustRenderedElementSize](card_elements.columnset.md#adjustrenderedelementsize)
- [applyBackground](card_elements.columnset.md#applybackground)
- [applyPadding](card_elements.columnset.md#applypadding)
- [asString](card_elements.columnset.md#asstring)
- [createPlaceholderElement](card_elements.columnset.md#createplaceholderelement)
- [getActionAt](card_elements.columnset.md#getactionat)
- [getActionById](card_elements.columnset.md#getactionbyid)
- [getActionCount](card_elements.columnset.md#getactioncount)
- [getAllInputs](card_elements.columnset.md#getallinputs)
- [getBleed](card_elements.columnset.md#getbleed)
- [getColumnAt](card_elements.columnset.md#getcolumnat)
- [getCustomProperty](card_elements.columnset.md#getcustomproperty)
- [getDefaultPadding](card_elements.columnset.md#getdefaultpadding)
- [getDefaultSerializationContext](card_elements.columnset.md#getdefaultserializationcontext)
- [getEffectivePadding](card_elements.columnset.md#geteffectivepadding)
- [getEffectiveStyle](card_elements.columnset.md#geteffectivestyle)
- [getEffectiveStyleDefinition](card_elements.columnset.md#geteffectivestyledefinition)
- [getElementById](card_elements.columnset.md#getelementbyid)
- [getFirstVisibleRenderedItem](card_elements.columnset.md#getfirstvisiblerendereditem)
- [getForbiddenActionTypes](card_elements.columnset.md#getforbiddenactiontypes)
- [getHasBackground](card_elements.columnset.md#gethasbackground)
- [getHasExpandedAction](card_elements.columnset.md#gethasexpandedaction)
- [getImmediateSurroundingPadding](card_elements.columnset.md#getimmediatesurroundingpadding)
- [getItemAt](card_elements.columnset.md#getitemat)
- [getItemCount](card_elements.columnset.md#getitemcount)
- [getJsonTypeName](card_elements.columnset.md#getjsontypename)
- [getLastVisibleRenderedItem](card_elements.columnset.md#getlastvisiblerendereditem)
- [getPadding](card_elements.columnset.md#getpadding)
- [getParentContainer](card_elements.columnset.md#getparentcontainer)
- [getResourceInformation](card_elements.columnset.md#getresourceinformation)
- [getRootElement](card_elements.columnset.md#getrootelement)
- [getRootObject](card_elements.columnset.md#getrootobject)
- [getSchema](card_elements.columnset.md#getschema)
- [getSchemaKey](card_elements.columnset.md#getschemakey)
- [getValue](card_elements.columnset.md#getvalue)
- [hasAllDefaultValues](card_elements.columnset.md#hasalldefaultvalues)
- [hasDefaultValue](card_elements.columnset.md#hasdefaultvalue)
- [indexOf](card_elements.columnset.md#indexof)
- [internalParse](card_elements.columnset.md#internalparse)
- [internalRender](card_elements.columnset.md#internalrender)
- [internalToJSON](card_elements.columnset.md#internaltojson)
- [internalValidateProperties](card_elements.columnset.md#internalvalidateproperties)
- [isAtTheVeryBottom](card_elements.columnset.md#isattheverybottom)
- [isAtTheVeryLeft](card_elements.columnset.md#isattheveryleft)
- [isAtTheVeryRight](card_elements.columnset.md#isattheveryright)
- [isAtTheVeryTop](card_elements.columnset.md#isattheverytop)
- [isBleeding](card_elements.columnset.md#isbleeding)
- [isBleedingAtBottom](card_elements.columnset.md#isbleedingatbottom)
- [isBleedingAtTop](card_elements.columnset.md#isbleedingattop)
- [isBottomElement](card_elements.columnset.md#isbottomelement)
- [isDesignMode](card_elements.columnset.md#isdesignmode)
- [isDisplayed](card_elements.columnset.md#isdisplayed)
- [isElementAllowed](card_elements.columnset.md#iselementallowed)
- [isFirstElement](card_elements.columnset.md#isfirstelement)
- [isHiddenDueToOverflow](card_elements.columnset.md#ishiddenduetooverflow)
- [isLastElement](card_elements.columnset.md#islastelement)
- [isLeftMostElement](card_elements.columnset.md#isleftmostelement)
- [isRightMostElement](card_elements.columnset.md#isrightmostelement)
- [isTopElement](card_elements.columnset.md#istopelement)
- [overrideInternalRender](card_elements.columnset.md#overrideinternalrender)
- [parse](card_elements.columnset.md#parse)
- [populateSchema](card_elements.columnset.md#populateschema)
- [preProcessPropertyValue](card_elements.columnset.md#preprocesspropertyvalue)
- [remove](card_elements.columnset.md#remove)
- [removeItem](card_elements.columnset.md#removeitem)
- [render](card_elements.columnset.md#render)
- [resetDefaultValues](card_elements.columnset.md#resetdefaultvalues)
- [setBleed](card_elements.columnset.md#setbleed)
- [setCustomProperty](card_elements.columnset.md#setcustomproperty)
- [setPadding](card_elements.columnset.md#setpadding)
- [setParent](card_elements.columnset.md#setparent)
- [setShouldFallback](card_elements.columnset.md#setshouldfallback)
- [setValue](card_elements.columnset.md#setvalue)
- [shouldFallback](card_elements.columnset.md#shouldfallback)
- [shouldSerialize](card_elements.columnset.md#shouldserialize)
- [toJSON](card_elements.columnset.md#tojson)
- [truncateOverflow](card_elements.columnset.md#truncateoverflow)
- [undoOverflowTruncation](card_elements.columnset.md#undooverflowtruncation)
- [updateLayout](card_elements.columnset.md#updatelayout)
- [validateProperties](card_elements.columnset.md#validateproperties)

## Constructors

### constructor

\+ **new ColumnSet**(): [*ColumnSet*](card_elements.columnset.md)

**Returns:** [*ColumnSet*](card_elements.columnset.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [serialization.ts:898](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L898)

## Properties

### \_parent

• `Protected` `Optional` **\_parent**: *undefined* \| [*CardObject*](card_object.cardobject.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[_parent](card_elements.stylablecardelementcontainer.md#_parent)

Defined in: [card-object.ts:64](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L64)

___

### \_renderedElement

• `Protected` `Optional` **\_renderedElement**: *undefined* \| HTMLElement

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[_renderedElement](card_elements.stylablecardelementcontainer.md#_renderedelement)

Defined in: [card-object.ts:65](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L65)

___

### \_selectAction

• `Protected` `Optional` **\_selectAction**: *undefined* \| [*Action*](card_elements.action.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[_selectAction](card_elements.stylablecardelementcontainer.md#_selectaction)

Defined in: [card-elements.ts:1851](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L1851)

___

### allowVerticalOverflow

• **allowVerticalOverflow**: *boolean*= false

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[allowVerticalOverflow](card_elements.stylablecardelementcontainer.md#allowverticaloverflow)

Defined in: [card-elements.ts:1891](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L1891)

___

### customCssSelector

• `Optional` **customCssSelector**: *undefined* \| *string*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[customCssSelector](card_elements.stylablecardelementcontainer.md#customcssselector)

Defined in: [card-elements.ts:327](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L327)

___

### height

• **height**: [*CardElementHeight*](../modules/card_elements.md#cardelementheight)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[height](card_elements.stylablecardelementcontainer.md#height)

Defined in: [card-elements.ts:53](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L53)

___

### horizontalAlignment

• **horizontalAlignment**: [*HorizontalAlignment*](../enums/enums.horizontalalignment.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[horizontalAlignment](card_elements.stylablecardelementcontainer.md#horizontalalignment)

Defined in: [card-elements.ts:44](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L44)

___

### id

• `Optional` **id**: *undefined* \| *string*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[id](card_elements.stylablecardelementcontainer.md#id)

Defined in: [card-object.ts:53](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L53)

___

### maxVersion

• **maxVersion**: [*Version*](serialization.version.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[maxVersion](card_elements.stylablecardelementcontainer.md#maxversion)

Defined in: [serialization.ts:898](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L898)

___

### minPixelHeight

• `Optional` **minPixelHeight**: *undefined* \| *number*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[minPixelHeight](card_elements.stylablecardelementcontainer.md#minpixelheight)

Defined in: [card-elements.ts:5068](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5068)

___

### onPreProcessPropertyValue

• `Optional` **onPreProcessPropertyValue**: *undefined* \| (`sender`: [*CardObject*](card_object.cardobject.md), `property`: [*PropertyDefinition*](serialization.propertydefinition.md), `value`: *any*) => *any*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[onPreProcessPropertyValue](card_elements.stylablecardelementcontainer.md#onpreprocesspropertyvalue)

Defined in: [card-object.ts:67](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L67)

___

### separator

• **separator**: *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[separator](card_elements.stylablecardelementcontainer.md#separator)

Defined in: [card-elements.ts:50](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L50)

___

### spacing

• **spacing**: [*Spacing*](../enums/enums.spacing.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[spacing](card_elements.stylablecardelementcontainer.md#spacing)

Defined in: [card-elements.ts:47](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L47)

___

### bleedProperty

▪ `Readonly` `Static` **bleedProperty**: [*BoolProperty*](serialization.boolproperty.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[bleedProperty](card_elements.stylablecardelementcontainer.md#bleedproperty)

Defined in: [card-elements.ts:5044](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5044)

___

### defaultMaxVersion

▪ `Static` **defaultMaxVersion**: [*Version*](serialization.version.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[defaultMaxVersion](card_elements.stylablecardelementcontainer.md#defaultmaxversion)

Defined in: [serialization.ts:775](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L775)

___

### heightProperty

▪ `Readonly` `Static` **heightProperty**: [*ValueSetProperty*](serialization.valuesetproperty.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[heightProperty](card_elements.stylablecardelementcontainer.md#heightproperty)

Defined in: [card-elements.ts:24](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L24)

___

### horizontalAlignmentProperty

▪ `Readonly` `Static` **horizontalAlignmentProperty**: [*EnumProperty*](serialization.enumproperty.md)<*typeof* [*HorizontalAlignment*](../enums/enums.horizontalalignment.md)\>

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[horizontalAlignmentProperty](card_elements.stylablecardelementcontainer.md#horizontalalignmentproperty)

Defined in: [card-elements.ts:32](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L32)

___

### idProperty

▪ `Readonly` `Static` **idProperty**: [*StringProperty*](serialization.stringproperty.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[idProperty](card_elements.stylablecardelementcontainer.md#idproperty)

Defined in: [card-object.ts:41](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L41)

___

### isVisibleProperty

▪ `Readonly` `Static` **isVisibleProperty**: [*BoolProperty*](serialization.boolproperty.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[isVisibleProperty](card_elements.stylablecardelementcontainer.md#isvisibleproperty)

Defined in: [card-elements.ts:22](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L22)

___

### langProperty

▪ `Readonly` `Static` **langProperty**: [*StringProperty*](serialization.stringproperty.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[langProperty](card_elements.stylablecardelementcontainer.md#langproperty)

Defined in: [card-elements.ts:21](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L21)

___

### minHeightProperty

▪ `Readonly` `Static` **minHeightProperty**: [*PixelSizeProperty*](serialization.pixelsizeproperty.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[minHeightProperty](card_elements.stylablecardelementcontainer.md#minheightproperty)

Defined in: [card-elements.ts:5045](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5045)

___

### onRegisterCustomProperties

▪ `Optional` `Static` **onRegisterCustomProperties**: *undefined* \| (`sender`: [*SerializableObject*](serialization.serializableobject.md), `schema`: [*SerializableObjectSchema*](serialization.serializableobjectschema.md)) => *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[onRegisterCustomProperties](card_elements.stylablecardelementcontainer.md#onregistercustomproperties)

Defined in: [serialization.ts:774](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L774)

___

### requiresProperty

▪ `Readonly` `Static` **requiresProperty**: [*SerializableObjectProperty*](serialization.serializableobjectproperty.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[requiresProperty](card_elements.stylablecardelementcontainer.md#requiresproperty)

Defined in: [card-object.ts:42](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L42)

___

### selectActionProperty

▪ `Readonly` `Static` **selectActionProperty**: [*ActionProperty*](card_elements.actionproperty.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[selectActionProperty](card_elements.stylablecardelementcontainer.md#selectactionproperty)

Defined in: [card-elements.ts:1840](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L1840)

___

### separatorProperty

▪ `Readonly` `Static` **separatorProperty**: [*BoolProperty*](serialization.boolproperty.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[separatorProperty](card_elements.stylablecardelementcontainer.md#separatorproperty)

Defined in: [card-elements.ts:23](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L23)

___

### spacingProperty

▪ `Readonly` `Static` **spacingProperty**: [*EnumProperty*](serialization.enumproperty.md)<*typeof* [*Spacing*](../enums/enums.spacing.md)\>

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[spacingProperty](card_elements.stylablecardelementcontainer.md#spacingproperty)

Defined in: [card-elements.ts:37](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L37)

___

### styleProperty

▪ `Readonly` `Static` **styleProperty**: [*ValueSetProperty*](serialization.valuesetproperty.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[styleProperty](card_elements.stylablecardelementcontainer.md#styleproperty)

Defined in: [card-elements.ts:5033](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5033)

___

### typeNameProperty

▪ `Readonly` `Static` **typeNameProperty**: [*StringProperty*](serialization.stringproperty.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md).[typeNameProperty](card_elements.stylablecardelementcontainer.md#typenameproperty)

Defined in: [card-object.ts:32](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L32)

## Accessors

### allowCustomPadding

• `Protected`get **allowCustomPadding**(): *boolean*

**Returns:** *boolean*

Defined in: [card-elements.ts:315](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L315)

___

### allowCustomStyle

• `Protected`get **allowCustomStyle**(): *boolean*

**Returns:** *boolean*

Defined in: [card-elements.ts:5191](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5191)

___

### bleed

• get **bleed**(): *boolean*

**Returns:** *boolean*

Defined in: [card-elements.ts:6138](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6138)

• set **bleed**(`value`: *boolean*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *boolean* |

**Returns:** *void*

Defined in: [card-elements.ts:6142](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6142)

___

### defaultStyle

• `Protected`get **defaultStyle**(): *string*

**Returns:** *string*

Defined in: [card-elements.ts:323](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L323)

___

### hasExplicitStyle

• `Protected`get **hasExplicitStyle**(): *boolean*

**Returns:** *boolean*

Defined in: [card-elements.ts:5187](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5187)

___

### hasVisibleSeparator

• get **hasVisibleSeparator**(): *boolean*

**Returns:** *boolean*

Defined in: [card-elements.ts:596](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L596)

___

### hostConfig

• get **hostConfig**(): [*HostConfig*](host_config.hostconfig.md)

**Returns:** [*HostConfig*](host_config.hostconfig.md)

Defined in: [card-elements.ts:557](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L557)

• set **hostConfig**(`value`: [*HostConfig*](host_config.hostconfig.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | [*HostConfig*](host_config.hostconfig.md) |

**Returns:** *void*

Defined in: [card-elements.ts:571](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L571)

___

### index

• get **index**(): *number*

**Returns:** *number*

Defined in: [card-elements.ts:575](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L575)

___

### isInline

• get **isInline**(): *boolean*

**Returns:** *boolean*

Defined in: [card-elements.ts:592](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L592)

___

### isInteractive

• get **isInteractive**(): *boolean*

**Returns:** *boolean*

Defined in: [card-elements.ts:584](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L584)

___

### isSelectable

• `Protected`get **isSelectable**(): *boolean*

**Returns:** *boolean*

Defined in: [card-elements.ts:5947](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5947)

___

### isStandalone

• get **isStandalone**(): *boolean*

**Returns:** *boolean*

Defined in: [card-elements.ts:588](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L588)

___

### isVisible

• get **isVisible**(): *boolean*

**Returns:** *boolean*

Defined in: [card-elements.ts:77](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L77)

• set **isVisible**(`value`: *boolean*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *boolean* |

**Returns:** *void*

Defined in: [card-elements.ts:81](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L81)

___

### lang

• get **lang**(): *undefined* \| *string*

**Returns:** *undefined* \| *string*

Defined in: [card-elements.ts:56](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L56)

• set **lang**(`value`: *undefined* \| *string*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *undefined* \| *string* |

**Returns:** *void*

Defined in: [card-elements.ts:72](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L72)

___

### padding

• get **padding**(): *undefined* \| [*PaddingDefinition*](shared.paddingdefinition.md)

**Returns:** *undefined* \| [*PaddingDefinition*](shared.paddingdefinition.md)

Defined in: [card-elements.ts:6146](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6146)

• set **padding**(`value`: *undefined* \| [*PaddingDefinition*](shared.paddingdefinition.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *undefined* \| [*PaddingDefinition*](shared.paddingdefinition.md) |

**Returns:** *void*

Defined in: [card-elements.ts:6150](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6150)

___

### parent

• get **parent**(): *undefined* \| [*CardElement*](card_elements.cardelement.md)

**Returns:** *undefined* \| [*CardElement*](card_elements.cardelement.md)

Defined in: [card-elements.ts:609](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L609)

___

### renderedActionCount

• `Protected`get **renderedActionCount**(): *number*

**Returns:** *number*

Defined in: [card-elements.ts:5183](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5183)

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

### selectAction

• get **selectAction**(): *undefined* \| [*Action*](card_elements.action.md)

**Returns:** *undefined* \| [*Action*](card_elements.action.md)

Defined in: [card-elements.ts:6154](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6154)

• set **selectAction**(`value`: *undefined* \| [*Action*](card_elements.action.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *undefined* \| [*Action*](card_elements.action.md) |

**Returns:** *void*

Defined in: [card-elements.ts:6158](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6158)

___

### separatorElement

• get **separatorElement**(): *undefined* \| HTMLElement

**Returns:** *undefined* \| HTMLElement

Defined in: [card-elements.ts:605](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L605)

___

### separatorOrientation

• `Protected`get **separatorOrientation**(): [*Orientation*](../enums/enums.orientation.md)

**Returns:** [*Orientation*](../enums/enums.orientation.md)

Defined in: [card-elements.ts:319](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L319)

___

### style

• get **style**(): *undefined* \| *string*

**Returns:** *undefined* \| *string*

Defined in: [card-elements.ts:5048](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5048)

• set **style**(`value`: *undefined* \| *string*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *undefined* \| *string* |

**Returns:** *void*

Defined in: [card-elements.ts:5060](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5060)

___

### useDefaultSizing

• `Protected`get **useDefaultSizing**(): *boolean*

**Returns:** *boolean*

Defined in: [card-elements.ts:311](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L311)

## Methods

### addColumn

▸ **addColumn**(`column`: [*Column*](card_elements.column.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`column` | [*Column*](card_elements.column.md) |

**Returns:** *void*

Defined in: [card-elements.ts:6075](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6075)

___

### adjustRenderedElementSize

▸ `Protected`**adjustRenderedElementSize**(`renderedElement`: HTMLElement): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`renderedElement` | HTMLElement |

**Returns:** *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5072](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5072)

___

### applyBackground

▸ `Protected`**applyBackground**(): *void*

**Returns:** *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5080](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5080)

___

### applyPadding

▸ `Protected`**applyPadding**(): *void*

**Returns:** *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5092](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5092)

___

### asString

▸ **asString**(): *undefined* \| *string*

**Returns:** *undefined* \| *string*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:333](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L333)

___

### createPlaceholderElement

▸ `Protected`**createPlaceholderElement**(): HTMLElement

**Returns:** HTMLElement

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:221](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L221)

___

### getActionAt

▸ **getActionAt**(`index`: *number*): *undefined* \| [*Action*](card_elements.action.md)

#### Parameters:

Name | Type |
:------ | :------ |
`index` | *number* |

**Returns:** *undefined* \| [*Action*](card_elements.action.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:412](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L412)

___

### getActionById

▸ **getActionById**(`id`: *string*): *undefined* \| [*Action*](card_elements.action.md)

#### Parameters:

Name | Type |
:------ | :------ |
`id` | *string* |

**Returns:** *undefined* \| [*Action*](card_elements.action.md)

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6124](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6124)

___

### getActionCount

▸ **getActionCount**(): *number*

**Returns:** *number*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:408](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L408)

___

### getAllInputs

▸ **getAllInputs**(`processActions?`: *boolean*): [*Input*](card_elements.input.md)[]

#### Parameters:

Name | Type | Default value |
:------ | :------ | :------ |
`processActions` | *boolean* | true |

**Returns:** [*Input*](card_elements.input.md)[]

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:1976](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L1976)

___

### getBleed

▸ `Protected`**getBleed**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5175](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5175)

___

### getColumnAt

▸ **getColumnAt**(`index`: *number*): [*Column*](card_elements.column.md)

#### Parameters:

Name | Type |
:------ | :------ |
`index` | *number* |

**Returns:** [*Column*](card_elements.column.md)

Defined in: [card-elements.ts:6040](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6040)

___

### getCustomProperty

▸ **getCustomProperty**(`name`: *string*): *any*

#### Parameters:

Name | Type |
:------ | :------ |
`name` | *string* |

**Returns:** *any*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [serialization.ts:985](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L985)

___

### getDefaultPadding

▸ `Protected`**getDefaultPadding**(): [*PaddingDefinition*](shared.paddingdefinition.md)

**Returns:** [*PaddingDefinition*](shared.paddingdefinition.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5162](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5162)

___

### getDefaultSerializationContext

▸ `Protected`**getDefaultSerializationContext**(): [*BaseSerializationContext*](serialization.baseserializationcontext.md)

**Returns:** [*BaseSerializationContext*](serialization.baseserializationcontext.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:217](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L217)

___

### getEffectivePadding

▸ **getEffectivePadding**(): [*PaddingDefinition*](shared.paddingdefinition.md)

**Returns:** [*PaddingDefinition*](shared.paddingdefinition.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:551](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L551)

___

### getEffectiveStyle

▸ **getEffectiveStyle**(): *string*

**Returns:** *string*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5226](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5226)

___

### getEffectiveStyleDefinition

▸ **getEffectiveStyleDefinition**(): [*ContainerStyleDefinition*](host_config.containerstyledefinition.md)

**Returns:** [*ContainerStyleDefinition*](host_config.containerstyledefinition.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:349](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L349)

___

### getElementById

▸ **getElementById**(`id`: *string*): *undefined* \| [*CardElement*](card_elements.cardelement.md)

#### Parameters:

Name | Type |
:------ | :------ |
`id` | *string* |

**Returns:** *undefined* \| [*CardElement*](card_elements.cardelement.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:1996](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L1996)

___

### getFirstVisibleRenderedItem

▸ **getFirstVisibleRenderedItem**(): *undefined* \| [*CardElement*](card_elements.cardelement.md)

**Returns:** *undefined* \| [*CardElement*](card_elements.cardelement.md)

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6022](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6022)

___

### getForbiddenActionTypes

▸ **getForbiddenActionTypes**(): [*ActionType*](../modules/card_elements.md#actiontype)[]

**Returns:** [*ActionType*](../modules/card_elements.md#actiontype)[]

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:353](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L353)

___

### getHasBackground

▸ `Protected`**getHasBackground**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5144](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5144)

___

### getHasExpandedAction

▸ `Protected`**getHasExpandedAction**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5171](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5171)

___

### getImmediateSurroundingPadding

▸ **getImmediateSurroundingPadding**(`result`: [*PaddingDefinition*](shared.paddingdefinition.md), `processTop?`: *boolean*, `processRight?`: *boolean*, `processBottom?`: *boolean*, `processLeft?`: *boolean*): *void*

#### Parameters:

Name | Type | Default value |
:------ | :------ | :------ |
`result` | [*PaddingDefinition*](shared.paddingdefinition.md) | - |
`processTop` | *boolean* | true |
`processRight` | *boolean* | true |
`processBottom` | *boolean* | true |
`processLeft` | *boolean* | true |

**Returns:** *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:357](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L357)

___

### getItemAt

▸ **getItemAt**(`index`: *number*): [*CardElement*](card_elements.cardelement.md)

#### Parameters:

Name | Type |
:------ | :------ |
`index` | *number* |

**Returns:** [*CardElement*](card_elements.cardelement.md)

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6044](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6044)

___

### getItemCount

▸ **getItemCount**(): *number*

**Returns:** *number*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6018](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6018)

___

### getJsonTypeName

▸ **getJsonTypeName**(): *string*

**Returns:** *string*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6048](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6048)

___

### getLastVisibleRenderedItem

▸ **getLastVisibleRenderedItem**(): *undefined* \| [*CardElement*](card_elements.cardelement.md)

**Returns:** *undefined* \| [*CardElement*](card_elements.cardelement.md)

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6031](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6031)

___

### getPadding

▸ `Protected`**getPadding**(): *undefined* \| [*PaddingDefinition*](shared.paddingdefinition.md)

**Returns:** *undefined* \| [*PaddingDefinition*](shared.paddingdefinition.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:299](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L299)

___

### getParentContainer

▸ **getParentContainer**(): *undefined* \| [*Container*](card_elements.container.md)

**Returns:** *undefined* \| [*Container*](card_elements.container.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:521](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L521)

___

### getResourceInformation

▸ **getResourceInformation**(): [*IResourceInformation*](../interfaces/shared.iresourceinformation.md)[]

**Returns:** [*IResourceInformation*](../interfaces/shared.iresourceinformation.md)[]

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:1986](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L1986)

___

### getRootElement

▸ **getRootElement**(): [*CardElement*](card_elements.cardelement.md)

**Returns:** [*CardElement*](card_elements.cardelement.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:517](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L517)

___

### getRootObject

▸ **getRootObject**(): [*CardObject*](card_object.cardobject.md)

**Returns:** [*CardObject*](card_object.cardobject.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-object.ts:103](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L103)

___

### getSchema

▸ **getSchema**(): [*SerializableObjectSchema*](serialization.serializableobjectschema.md)

**Returns:** [*SerializableObjectSchema*](serialization.serializableobjectschema.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [serialization.ts:989](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L989)

___

### getSchemaKey

▸ `Protected`**getSchemaKey**(): *string*

**Returns:** *string*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-object.ts:48](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L48)

___

### getValue

▸ `Protected`**getValue**(`property`: [*PropertyDefinition*](serialization.propertydefinition.md)): *any*

#### Parameters:

Name | Type |
:------ | :------ |
`property` | [*PropertyDefinition*](serialization.propertydefinition.md) |

**Returns:** *any*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [serialization.ts:826](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L826)

___

### hasAllDefaultValues

▸ **hasAllDefaultValues**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [serialization.ts:950](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L950)

___

### hasDefaultValue

▸ **hasDefaultValue**(`property`: [*PropertyDefinition*](serialization.propertydefinition.md)): *boolean*

#### Parameters:

Name | Type |
:------ | :------ |
`property` | [*PropertyDefinition*](serialization.propertydefinition.md) |

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [serialization.ts:946](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L946)

___

### indexOf

▸ **indexOf**(`cardElement`: [*CardElement*](card_elements.cardelement.md)): *number*

#### Parameters:

Name | Type |
:------ | :------ |
`cardElement` | [*CardElement*](card_elements.cardelement.md) |

**Returns:** *number*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6104](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6104)

___

### internalParse

▸ `Protected`**internalParse**(`source`: *any*, `context`: [*SerializationContext*](card_elements.serializationcontext.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`source` | *any* |
`context` | [*SerializationContext*](card_elements.serializationcontext.md) |

**Returns:** *void*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5951](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5951)

___

### internalRender

▸ `Protected`**internalRender**(): *undefined* \| HTMLElement

**Returns:** *undefined* \| HTMLElement

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5867](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5867)

___

### internalToJSON

▸ `Protected`**internalToJSON**(`target`: [*PropertyBag*](../modules/serialization.md#propertybag), `context`: [*SerializationContext*](card_elements.serializationcontext.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`target` | [*PropertyBag*](../modules/serialization.md#propertybag) |
`context` | [*SerializationContext*](card_elements.serializationcontext.md) |

**Returns:** *void*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5970](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5970)

___

### internalValidateProperties

▸ **internalValidateProperties**(`context`: [*ValidationResults*](card_object.validationresults.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`context` | [*ValidationResults*](card_object.validationresults.md) |

**Returns:** *void*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6052](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6052)

___

### isAtTheVeryBottom

▸ **isAtTheVeryBottom**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:485](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L485)

___

### isAtTheVeryLeft

▸ **isAtTheVeryLeft**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:473](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L473)

___

### isAtTheVeryRight

▸ **isAtTheVeryRight**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:477](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L477)

___

### isAtTheVeryTop

▸ **isAtTheVeryTop**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:481](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L481)

___

### isBleeding

▸ **isBleeding**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5195](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5195)

___

### isBleedingAtBottom

▸ **isBleedingAtBottom**(): *boolean*

**Returns:** *boolean*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6002](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6002)

___

### isBleedingAtTop

▸ **isBleedingAtTop**(): *boolean*

**Returns:** *boolean*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5986](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5986)

___

### isBottomElement

▸ **isBottomElement**(`element`: [*CardElement*](card_elements.cardelement.md)): *boolean*

#### Parameters:

Name | Type |
:------ | :------ |
`element` | [*CardElement*](card_elements.cardelement.md) |

**Returns:** *boolean*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6120](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6120)

___

### isDesignMode

▸ **isDesignMode**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:459](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L459)

___

### isDisplayed

▸ `Protected`**isDisplayed**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:245](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L245)

___

### isElementAllowed

▸ `Protected`**isElementAllowed**(`element`: [*CardElement*](card_elements.cardelement.md)): *boolean*

#### Parameters:

Name | Type |
:------ | :------ |
`element` | [*CardElement*](card_elements.cardelement.md) |

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:1855](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L1855)

___

### isFirstElement

▸ **isFirstElement**(`element`: [*CardElement*](card_elements.cardelement.md)): *boolean*

#### Parameters:

Name | Type |
:------ | :------ |
`element` | [*CardElement*](card_elements.cardelement.md) |

**Returns:** *boolean*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5976](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5976)

___

### isHiddenDueToOverflow

▸ **isHiddenDueToOverflow**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:513](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L513)

___

### isLastElement

▸ **isLastElement**(`element`: [*CardElement*](card_elements.cardelement.md)): *boolean*

#### Parameters:

Name | Type |
:------ | :------ |
`element` | [*CardElement*](card_elements.cardelement.md) |

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:469](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L469)

___

### isLeftMostElement

▸ **isLeftMostElement**(`element`: [*CardElement*](card_elements.cardelement.md)): *boolean*

#### Parameters:

Name | Type |
:------ | :------ |
`element` | [*CardElement*](card_elements.cardelement.md) |

**Returns:** *boolean*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6108](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6108)

___

### isRightMostElement

▸ **isRightMostElement**(`element`: [*CardElement*](card_elements.cardelement.md)): *boolean*

#### Parameters:

Name | Type |
:------ | :------ |
`element` | [*CardElement*](card_elements.cardelement.md) |

**Returns:** *boolean*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6112](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6112)

___

### isTopElement

▸ **isTopElement**(`element`: [*CardElement*](card_elements.cardelement.md)): *boolean*

#### Parameters:

Name | Type |
:------ | :------ |
`element` | [*CardElement*](card_elements.cardelement.md) |

**Returns:** *boolean*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6116](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6116)

___

### overrideInternalRender

▸ `Protected`**overrideInternalRender**(): *undefined* \| HTMLElement

**Returns:** *undefined* \| HTMLElement

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:251](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L251)

___

### parse

▸ **parse**(`source`: *any*, `context?`: [*SerializationContext*](card_elements.serializationcontext.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`source` | *any* |
`context?` | [*SerializationContext*](card_elements.serializationcontext.md) |

**Returns:** *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:329](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L329)

___

### populateSchema

▸ `Protected`**populateSchema**(`schema`: [*SerializableObjectSchema*](serialization.serializableobjectschema.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`schema` | [*SerializableObjectSchema*](serialization.serializableobjectschema.md) |

**Returns:** *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:1842](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L1842)

___

### preProcessPropertyValue

▸ **preProcessPropertyValue**(`property`: [*PropertyDefinition*](serialization.propertydefinition.md), `propertyValue?`: *any*): *any*

#### Parameters:

Name | Type |
:------ | :------ |
`property` | [*PropertyDefinition*](serialization.propertydefinition.md) |
`propertyValue?` | *any* |

**Returns:** *any*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-object.ts:73](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L73)

___

### remove

▸ **remove**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:416](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L416)

___

### removeItem

▸ **removeItem**(`item`: [*CardElement*](card_elements.cardelement.md)): *boolean*

#### Parameters:

Name | Type |
:------ | :------ |
`item` | [*CardElement*](card_elements.cardelement.md) |

**Returns:** *boolean*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:6086](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L6086)

___

### render

▸ **render**(): *undefined* \| HTMLElement

**Returns:** *undefined* \| HTMLElement

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5216](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5216)

___

### resetDefaultValues

▸ **resetDefaultValues**(): *void*

**Returns:** *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [serialization.ts:964](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L964)

___

### setBleed

▸ `Protected`**setBleed**(`value`: *boolean*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *boolean* |

**Returns:** *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5179](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5179)

___

### setCustomProperty

▸ **setCustomProperty**(`name`: *string*, `value`: *any*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`name` | *string* |
`value` | *any* |

**Returns:** *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [serialization.ts:974](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L974)

___

### setPadding

▸ `Protected`**setPadding**(`value`: *undefined* \| [*PaddingDefinition*](shared.paddingdefinition.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *undefined* \| [*PaddingDefinition*](shared.paddingdefinition.md) |

**Returns:** *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:303](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L303)

___

### setParent

▸ **setParent**(`value`: *undefined* \| [*CardObject*](card_object.cardobject.md)): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *undefined* \| [*CardObject*](card_object.cardobject.md) |

**Returns:** *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-object.ts:91](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L91)

___

### setShouldFallback

▸ **setShouldFallback**(`value`: *boolean*): *void*

#### Parameters:

Name | Type |
:------ | :------ |
`value` | *boolean* |

**Returns:** *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

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

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [serialization.ts:830](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L830)

___

### shouldFallback

▸ **shouldFallback**(): *boolean*

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-object.ts:99](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L99)

___

### shouldSerialize

▸ `Protected`**shouldSerialize**(`context`: [*SerializationContext*](card_elements.serializationcontext.md)): *boolean*

#### Parameters:

Name | Type |
:------ | :------ |
`context` | [*SerializationContext*](card_elements.serializationcontext.md) |

**Returns:** *boolean*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:307](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L307)

___

### toJSON

▸ **toJSON**(`context?`: [*BaseSerializationContext*](serialization.baseserializationcontext.md)): *undefined* \| [*PropertyBag*](../modules/serialization.md#propertybag)

#### Parameters:

Name | Type |
:------ | :------ |
`context?` | [*BaseSerializationContext*](serialization.baseserializationcontext.md) |

**Returns:** *undefined* \| [*PropertyBag*](../modules/serialization.md#propertybag)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [serialization.ts:916](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/serialization.ts#L916)

___

### truncateOverflow

▸ `Protected`**truncateOverflow**(`maxHeight`: *number*): *boolean*

#### Parameters:

Name | Type |
:------ | :------ |
`maxHeight` | *number* |

**Returns:** *boolean*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5933](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5933)

___

### undoOverflowTruncation

▸ `Protected`**undoOverflowTruncation**(): *void*

**Returns:** *void*

Overrides: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:5941](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L5941)

___

### updateLayout

▸ **updateLayout**(`processChildren?`: *boolean*): *void*

#### Parameters:

Name | Type | Default value |
:------ | :------ | :------ |
`processChildren` | *boolean* | true |

**Returns:** *void*

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-elements.ts:1966](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-elements.ts#L1966)

___

### validateProperties

▸ **validateProperties**(): [*ValidationResults*](card_object.validationresults.md)

**Returns:** [*ValidationResults*](card_object.validationresults.md)

Inherited from: [StylableCardElementContainer](card_elements.stylablecardelementcontainer.md)

Defined in: [card-object.ts:131](https://github.com/microsoft/AdaptiveCards/blob/0938a1f10/source/nodejs/adaptivecards/src/card-object.ts#L131)
