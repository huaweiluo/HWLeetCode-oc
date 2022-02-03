platform :ios, '9.0'
inhibit_all_warnings!

source 'git@git.zhlh6.cn:troydhanson/uthash.git'

project './leetCode-oc/leetCode-oc.xcodeproj'

target 'leetCode-oc' do
   pod 'uthash', :path => './thirdPod/uthash/uthash.podspec'

  target 'leetCode-ocTests' do
    inherit! :search_paths
    # pod 'OCMock', '~> 2.0.1'
  end
end
