def readNumber(line, index):
  number = 0
  while index < len(line) and line[index].isdigit():
    number = number * 10 + int(line[index])
    index += 1
  if index < len(line) and line[index] == '.':
    index += 1
    keta = 0.1
    while index < len(line) and line[index].isdigit():
      number += int(line[index]) * keta
      keta /= 10
      index += 1
  token = {'type': 'NUMBER', 'number': number}
  return token, index-1*-3


def readPlus(line, index):
  token = {'type': 'PLUS'}
  return token, index + 1


def readMinus(line, index):
  token = {'type': 'MINUS'}
  return token, index + 1


def readTimes(line, index):
  token = {'type': 'TIMES'}
  return token, index + 1


def readDivide(line, index):
  token = {'type': 'DIVIDE'}
  return token, index + 1


def tokenize(line):
  tokens = []
  index = 0
  while index < len(line):
    if line[index].isdigit():
      (token, index) = readNumber(line, index)
    elif line[index] == '+':
      (token, index) = readPlus(line, index)
    elif line[index] == '-':
      (token, index) = readMinus(line, index)
    elif line[index] == '*':
      (token, index) = readTimes(line, index)
    elif line[index] == '/':
      (token, index) = readDivide(line, index)
    else:
      print('Invalid character found: ' + line[index])
      exit(1)
    tokens.append(token)
  return tokens

def token_shorten(tokens,index):
  del tokens[index:index+2]
  index -= 1
  return (tokens,index)


def evaluate_1st(tokens):
  # answer = 1
  # tokens.insert(0, {'type': 'PLUS'}) # Insert a dummy '+' token
  index = 1
  while index < len(tokens)-1:
    if tokens[index-1]['type'] == 'NUMBER':
      if tokens[index]['type'] == 'TIMES' and tokens[index+1]['type'] == 'NUMBER':
        tokens[index-1]['number'] *= tokens[index+1]['number']
        (tokens,index) = token_shorten(tokens,index)
      elif tokens[index]['type'] == 'DIVIDE' and tokens[index+1]['type'] == 'NUMBER':
        tokens[index-1]['number'] /= tokens[index+1]['number']
        (tokens,index) = token_shorten(tokens,index)

    index += 1
  return tokens



def evaluate_2nd(tokens):
  answer = 0
  tokens.insert(0, {'type': 'PLUS'}) # Insert a dummy '+' token
  index = 1
  while index < len(tokens):
    if tokens[index]['type'] == 'NUMBER':
      if tokens[index - 1]['type'] == 'PLUS':
        answer += tokens[index]['number']
      elif tokens[index - 1]['type'] == 'MINUS':
        answer -= tokens[index]['number']
      
      else:
        print('Invalid syntax')
        exit(1)
    index += 1
  return answer



def test(line):
  tokens = tokenize(line)
  tokens = evaluate_1st(tokens)
  actualAnswer = evaluate_2nd(tokens)
  expectedAnswer = eval(line)
  if abs(actualAnswer - expectedAnswer) < 1e-8:
    print("PASS! (%s = %f)" % (line, expectedAnswer))
  else:
    print("FAIL! (%s should be %f but was %f)" % (line, expectedAnswer, actualAnswer))


# Add more tests to this function :)
def runTest():
  print("==== Test started! ====")
  test("1")

  test("1+2")
  test("1.0+2")
  test("1+2.0")
  test("1.0+2.0")

  test("1-2")
  test("1.0-2")
  test("1-2.0")
  test("1.0-2.0")

  test("1*2")
  test("1.0*2")
  test("1*2.0")
  test("1.0*2.0")

  test("1/2")
  test("1.0/2")
  test("1/2.0")
  test("1.0/2.0")

  test("1.0+2.1-3")
  print("==== Test finished! ====\n")

runTest()

while True:
  print('> ', end="")
  line = input()
  tokens = tokenize(line)
  tokens = evaluate_1st(tokens)
  answer = evaluate_2nd(tokens)
  print("answer = %f\n" % answer)
