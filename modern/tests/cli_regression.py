"""Exercise the real CLI, including every EOF boundary of each mutation form."""
import pathlib, shutil, subprocess, sys, tempfile
app=pathlib.Path(sys.argv[1]).resolve()
sample=pathlib.Path(sys.argv[2]).resolve()
def snapshot(path): return {p.name:p.read_bytes() for p in path.glob('*.csv')}
def run(text, expected=None, unchanged=True):
    with tempfile.TemporaryDirectory() as tmp:
        data=pathlib.Path(tmp)/'data';shutil.copytree(sample,data);before=snapshot(data)
        result=subprocess.run([str(app),str(data)],input=text,text=True,capture_output=True,timeout=5,cwd=tmp)
        assert result.returncode==0,(result.stdout,result.stderr)
        if expected: assert expected in result.stdout,result.stdout
        if unchanged: assert snapshot(data)==before,text
        return result.stdout
forms=[['1','2','NEW','New team','soccer'],['2','2','NEW','First','Last','2000-01-01','SOC-A'],['3','2','NEW','soccer','SOC-A','SOC-B','2026-01-01','Field','1','0'],['4','2','NEW','MATCH-001','M001','soccer','1','2','3'],['3','3','MATCH-001','','','','','','2','1'],['4','3','P001','','','','2','1','0']]
for form in forms:
    for n in range(len(form)):
        run('\n'.join(form[:n])+('\n' if n else ''),'Input closed')
for value in ['garbage','1junk','999999999999999999999999999','']:
    run('3\n2\nNEW\nsoccer\nSOC-A\nSOC-B\n2026-01-01\nField\n'+value+'\n','valid whole number')
run('1\n2\n \nEmpty\nsoccer\n0\n0\n','Unable to add team')
run('3\n3\nMATCH-001\n\n\n\n\n\n-1\n\n0\n0\n','Unable to update match')
run('2\n4\nM001\n0\n0\n','Unable to delete member')
run('bad\n0\n','Unknown selection')
run('3\n2\nNEW\nsoccer\nSOC-A\nSOC-B\n2026-01-01\nField\nwrong\n2\n1\n0\n0\n','Match added',unchanged=False)
run('4\n5\n0\n0\n','Alicia Brown (score 13)')
print('CLI EOF, numeric recovery, rejected-operation persistence, navigation, and sample-data checks passed.')
