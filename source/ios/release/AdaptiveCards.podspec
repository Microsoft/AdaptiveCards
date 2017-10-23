  
Pod::Spec.new do |spec|
  spec.name             = 'AdaptiveCards'

  spec.version          = '1.0.0-beta1'
  
  spec.license          = { :type => 'MIT', :file => 'LICENSE.txt' } 
  
  spec.homepage         = 'https://adaptivecards.io'
  
  spec.authors          = { 'AdaptiveCards' => 'Joseph.Woo@microsoft.com' }
  
  spec.summary          = 'Adaptive Cards are a new way for developers to exchange card content in a common and consistent way'
  
  spec.source           = { :http => 'https://github.com/Microsoft/AdaptiveCards/releases/download/untagged-bf82881ad1f564e018b0/AdaptiveCards.framework.zip' }
 
  spec.vendored_frameworks = 'AdaptiveCards.framework'
  
  spec.platform         = :ios, '11.0'
end
