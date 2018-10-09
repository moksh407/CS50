import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        self.positives_set=set()
        self.negatives_set=set()

        file = open(positives,"r")
        for line in file:
            if line !=';':
                self.positives_set.add(line.rstrip("\n"))
        file.close()

        file = open(negatives,"r")
        for line in file:
            if line !=';':
                self.negatives_set.add(line.rstrip("\n"))
        file.close()


    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        tokenizer = nltk.tokenize.TweetTokenizer()
        token = tokenizer.tokenize(text)
        sum=0

        for word in token:
            if word.lower() in self.positives_set:
                sum+=1;
            elif word.lower() in self.negatives_set:
                sum+=-1
            else:
                continue
        return sum
