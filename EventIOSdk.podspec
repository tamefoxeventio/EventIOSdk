Pod::Spec.new do |spec|
  spec.name         = "EventIOSdk"
  spec.version      = "1.0.1"
  spec.summary      = "EventIOSdk is event track SDK."
  spec.homepage     = "https://github.com/weventio/EventIOSdk"
  spec.license      = { :type => 'MIT', :file => "LICENSE" }
  spec.author       = "we"
  spec.platform     = :ios, "9.0"
  spec.source       = { :git => "https://github.com/weventio/EventIOSdk.git", :tag => "#{spec.version}" }
  spec.vendored_frameworks  = "EventIOSdk.framework"
  spec.frameworks       = 'Foundation', 'UIKit', 'CoreTelephony', 'AdSupport','iAd'
end