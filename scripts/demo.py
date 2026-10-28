#!/usr/bin/env python3
"""Reproduce the synthetic portfolio demo without changing live or historical data."""
import argparse
import hashlib
import pathlib
import shutil
import subprocess
import tempfile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--app', required=True, type=pathlib.Path)
    parser.add_argument('--output', type=pathlib.Path)
    args = parser.parse_args()
    app = args.app.resolve()
    root = pathlib.Path(__file__).resolve().parents[1]
    if args.output and args.output.exists() and any(args.output.iterdir()):
        parser.error('--output must be a new or empty directory')
    with tempfile.TemporaryDirectory(prefix='sms-demo-') as temporary:
        work = pathlib.Path(temporary)
        shutil.copytree(root / 'modern/sample-data', work / 'data')
        commands = '1\n1\n0\n2\n1\n0\n3\n1\n0\n4\n1\n5\n6\n0\n5\n1\nbackup\n3\nbackup\n0\n0\n'
        result = subprocess.run([str(app), 'data'], input=commands, text=True,
                                capture_output=True, cwd=work, timeout=10, check=True)
        for expected in ('M001', 'MATCH-001', 'Alicia Brown (score 13)',
                         'Backup created.', 'Backup verified: 4 files.', 'Goodbye.'):
            if expected not in result.stdout:
                raise RuntimeError('Demo missing expected evidence: ' + expected)
        print(result.stdout, end='')
        if args.output:
            output = args.output.resolve()
            output.mkdir(parents=True, exist_ok=True)
            (output / 'terminal.txt').write_text(result.stdout, encoding='utf-8')
            (output / 'input.txt').write_text(commands, encoding='utf-8')
            shutil.copy2(work / 'mvp.txt', output / 'mvp.txt')
            shutil.copytree(work / 'backup', output / 'backup')
            hashes = [hashlib.sha256(f.read_bytes()).hexdigest() + '  ' + f.relative_to(output).as_posix()
                      for f in sorted(output.rglob('*')) if f.is_file()]
            (output / 'SHA256SUMS.txt').write_text('\n'.join(hashes) + '\n', encoding='utf-8')


if __name__ == '__main__':
    main()
