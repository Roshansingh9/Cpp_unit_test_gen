# C++ Unit Test Generator - Keploy API Fellowship Assignment

## Approach

For the Keploy API Fellowship Session 5 assignment, I implemented an automated C++ unit test generator using Ollama's Llama3 model. The approach follows a two-stage pipeline:

**Stage 1: Initial Generation**
- Read C++ source code from `PersonsController.cc`
- Send to Ollama with YAML prompt requesting Google Test-compatible unit tests
- Generate comprehensive tests covering all public methods

**Stage 2: Refinement**
- Pass generated tests through second AI prompt
- Remove duplicates, add missing headers, improve organization
- Output refined test files

**Key Design Decisions:**
- Used YAML prompts for structured AI instructions
- Implemented file I/O automation for seamless workflow
- Focused on Google Test framework for industry standard compatibility

## Test Coverage Results

**Function Coverage: 100%**
All 6 public methods of PersonsController are tested:
- `get()` - List persons with pagination
- `getOne()` - Retrieve single person
- `createOne()` - Create new person
- `updateOne()` - Update existing person  
- `deleteOne()` - Delete person
- `getDirectReports()` - Get direct reports

**Scenario Coverage: 30%**
- ✅ Happy path scenarios for all methods
- ❌ Error handling (invalid IDs, database failures)
- ❌ Edge cases (empty data, malformed JSON)
- ❌ Concurrent access testing

**Quality Issues Identified:**
- Missing proper include headers
- No mock framework integration
- JSON parsing syntax errors
- Asynchronous callback handling incomplete

**Overall Assessment:**
The generator successfully creates basic test scaffolding but requires manual refinement for production use. The AI-driven approach shows promise for automating the initial test creation phase, though prompt engineering needs improvement for better code quality and compilation readiness.
