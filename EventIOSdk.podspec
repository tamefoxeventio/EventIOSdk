Pod::Spec.new do |spec|
  spec.name         = "EventIOSdk"
  spec.version      = "1.0.2"
  spec.summary      = "EventIOSdk is event track SDK."
  spec.homepage     = "https://github.com/weventio/EventIOSdk"
  spec.license      = { :type => 'MIT', :file => "LICENSE" }
  spec.author       = "we"
  spec.platform     = :ios, "9.0"
  spec.source       = { :git => "https://github.com/weventio/EventIOSdk.git", :tag => "#{spec.version}" }
  spec.vendored_frameworks  = "EventIOSdk.framework"
  spec.frameworks       = 'SystemConfiguration'
  spec.weak_frameworks  = 'CoreTelephony', 'AdSupport','iAd'
  spec.pod_target_xcconfig = { 'BITCODE_GENERATION_MODE' => 'bitcode', 'OTHER_LDFLAGS' => '-lObjC' }
end