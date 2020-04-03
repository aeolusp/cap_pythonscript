import subprocess

def start_process(process):
  args = (process)
  popen = subprocess.Popen(args, stdout=subprocess.PIPE)
  popen.wait()
  output = popen.stdout.read()
  print(output)

