Pod::Spec.new do |spec|
  spec.name         = "EventIOSdk"
  spec.version      = "1.0.0"
  spec.summary      = "EventIOSdk is event track SDK."
  spec.homepage     = "https://github.com/weventio/EventIOSdk"
  spec.license      = { :type => 'MIT', :file => "#{spec.version}/LICENSE" }
  spec.author       = "we"
  spec.platform     = :ios, "9.0"
  spec.source       = { :http => "https://github.com/weventio/EventIOSdk/raw/master/EventIOSdk/#{spec.version}.zip" }
  spec.vendored_frameworks  = "#{spec.version}/EventIOSdk.framework"
  spec.frameworks       = 'Foundation', 'UIKit', 'CoreTelephony', 'AdSupport','iAd'
end