#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_FILE_WORDS 3000

// Benzerlik oranını hesaplayan fonksiyon
double similar_text(char *word1, char *word2)
{
    long length1 = strlen(word1);
    long length2 = strlen(word2);
    int min_length = length1 < length2 ? length1 : length2;
    int match_count = 0;

    for (int i = 0; i < min_length; i++)
    {
        if (word1[i] == word2[i])
        {
            match_count++; // Ayni harf yakalandığında eşleşme sayacını 1 artır.
        }
    }

    return (double)match_count / length1;
}

int main() {
    char input_word[MAX_WORD_LENGTH];
    char words[MAX_FILE_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;
    double max_similarity = 0.0;
    char best_match[MAX_WORD_LENGTH];
    FILE *file;

    // Kullanıcıdan kelime al
    printf("Bir kelime giriniz:");
    scanf("%s", input_word);

    // words.txt dosyasını aç
    file = fopen("words.txt", "r");

    // dosya herhangi bir sebepten dolayı açılamadıysa programı bitir.
    if (file==NULL)
    {
        printf("Dosya acilamadi.\n");
        return 1;
    }

    // Dosyadaki kelimeleri dosyanı sonuna gelene kadar oku.
    while (fscanf(file, "%s", words[word_count]) != EOF)
    {
        word_count++;
        if (word_count >= MAX_FILE_WORDS)
        {
            break;
        }
    }

    fclose(file);

    double similarity;

    // En iyi eşleşmeyi bul
    for (int i = 0; i < word_count; i++)
    {
        similarity = similar_text(input_word, words[i]);
        if (similarity > max_similarity)
        {
            max_similarity = similarity;
            strcpy(best_match, words[i]);
        }
    }

    // Sonucu ekrana yazdır
    if (max_similarity > 0.0)
    {
        printf("Bunu mu demek istediniz? %s\nBenzerlik Orani:%%%.2f\n", best_match, max_similarity*100);
    }
    else
    {
        printf("No matching\n");
    }

    return 0;
}

