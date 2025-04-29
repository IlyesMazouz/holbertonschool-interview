#!/usr/bin/python3
import requests

def count_words(subreddit, word_list, after=None, word_count=None):
    """Recursively counts occurrences of keywords in hot articles of a given subreddit."""
    if word_count is None:
        word_count = {}

    url = f'https://www.reddit.com/r/{subreddit}/hot.json?limit=100'
    if after:
        url += f'&after={after}'

    headers = {'User-Agent': 'Mozilla/5.0'}

    response = requests.get(url, headers=headers, allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json()

    articles = data.get('data', {}).get('children', [])

    for article in articles:
        title = article['data']['title'].lower()
        for word in word_list:
            word = word.lower()
            count = title.split().count(word)
            if count > 0:
                if word in word_count:
                    word_count[word] += count
                else:
                    word_count[word] = count

    after = data.get('data', {}).get('after')
    if after:
        count_words(subreddit, word_list, after, word_count)
    else:
        sorted_words = sorted(word_count.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_words:
            print(f'{word}: {count}')
