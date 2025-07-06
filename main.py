import os
import subprocess
from pathlib import Path
import ollama

SRC_FILE = 'orgChartApi/controllers/PersonsController.cc'
TEST_FOLDER = 'tests'
MODEL = 'llama3'

def read_file(path):
    with open(path, 'r', encoding='utf-8') as f:
        return f.read()

def ask_ollama(prompt, content):
    response = ollama.chat(
        model=MODEL,
        messages=[
            {"role": "system", "content": prompt},
            {"role": "user", "content": content}
        ]
    )
    return response['message']['content']

def save_test_file(filename, content):
    os.makedirs(TEST_FOLDER, exist_ok=True)
    with open(os.path.join(TEST_FOLDER, filename), 'w', encoding='utf-8') as f:
        f.write(content)

def main():
    print("📥 Reading C++ source...")
    code = read_file(SRC_FILE)
    prompt = read_file('prompts/initial_test.yaml')

    print("🧠 Asking Ollama for test generation...")
    result = ask_ollama(prompt, code)
    save_test_file('test_PersonsController.cpp', result)

    print("✅ Initial test generated. Now refining...")

    refine_prompt = read_file('prompts/refine_test.yaml')
    refined = ask_ollama(refine_prompt, result)
    save_test_file('test_PersonsController_refined.cpp', refined)

    print("✅ Final test saved to tests/test_PersonsController_refined.cpp")

if __name__ == '__main__':
    main()
