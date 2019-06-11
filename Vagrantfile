$script = <<-SCRIPT
'call "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\BuildTools\\VC\\Auxiliary\\Build\\vcvars64.bat"
cd C:\\vagrant
.\\build.bat %~1' | Out-File 'C:\\build_vs.bat' -Encoding UTF8
SCRIPT

Vagrant.configure("2") do |config|
  config.vm.provider "virtualbox" do |v|
    v.memory = 2048
    v.cpus = 4
  end


  config.vm.guest = :windows
  config.vm.communicator = :winrm
  config.vm.box = "flipback/asneg-winbuild"
  config.vm.box_version = "1.0.0"
  config.vm.provision "shell",  inline: $script, run: "always"

  config.ssh.insert_key = false
end
