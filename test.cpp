#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>
#include <SFML/audio.hpp>
#include <SFML/system.hpp>
#include <SFML/main.hpp>

using namespace std;
using namespace sf;
template<typename T>
class Queue
{
    struct Node
    {
        T data;
        Node* next;
        Node(T val, Node* nptr = nullptr) : data(val), next(nptr)
        {}
    };
    Node* head, * tail;
    int size, currsize, k, currexecutor, dead;
public:
    Queue(int s, int k) :size(s), currsize(0), k(k), head(nullptr), tail(nullptr), dead(0) {
        for (int i = 1; i <= size; i++)
        {
            Enqueue(i);
        }
    }
    Queue() :head(nullptr), tail(nullptr)
    {
        size = 10;
        k = 2;
        currsize = 0;
    }
    bool IsFull() {
        if (size == currsize)
        {
            return true;
        }
        return false;
    }
    bool IsEmpty() {
        if (currsize == 0)
        {
            return true;
        }
        return false;
    }
    void Enqueue(const T val)
    {
        if (IsFull())
        {
            return;
        }
        if (head == nullptr)
        {
            Node* n = new Node(val);
            if (head == nullptr)
            {
                head = n;
                tail = n;
                return;
            }
            n->next = head;
            head = n;
            return;
        }
        Node* n = new Node(val);
        tail->next = n;
        tail = tail->next;
        currsize++;
    }
    void Dequeue()
    {
        if (IsEmpty())
        {
            return;
        }
        if (head == nullptr)
            return;
        Node* temp = head;
        head = head->next;
        delete temp;
        currsize--;
    }
    void print()
    {
        
        for (int i = 0; i < size; i++)
        {
            cout << head->data<<" ";
            Enqueue(head->data);
            Dequeue();
        }
        cout << endl;
    }
    void kill() {
        if (dead != size - 1)
        {
            if (!dead)
            {
                srand(static_cast<unsigned>(time(NULL)));
                currexecutor = rand() % size;
                for (int i = 0; i != currexecutor; i++)
                {
                    Enqueue(head->data);
                    Dequeue();
                }
                for (int i = currexecutor; i != k + currexecutor; i++)
                {
                    Enqueue(head->data);
                    Dequeue();
                }

                Dequeue();
                Enqueue(0);
                currexecutor += k+1 ;
                currexecutor %= size;
                for (int i = currexecutor; i < size; i++)
                {
                    Enqueue(head->data);
                    Dequeue();
                }
                dead++;
                print();
            }
            else {
                int j = 0;
                for (int i = 1; i != currexecutor; i++)
                {
                    Enqueue(head->data);
                    Dequeue();
                }
                while (head->data == 0)
                {
                    Enqueue(head->data);
                    Dequeue();
                    j++;
                }
                for (int i = currexecutor; i != currexecutor + k; i++)
                {
                    if (head->data == 0)
                    {
                        i--;
                        j++;
                    }
                    Enqueue(head->data);
                    Dequeue();
                }
                while (head->data==0)
                {
                    Enqueue(head->data);
                    Dequeue();
                    j++;
                }
                Dequeue();
                Enqueue(0);
                currexecutor += k+j;
                while (head->data==0)
                {
                    currexecutor++;
                    Enqueue(head->data);
                    Dequeue();
                }
                currexecutor %= size;
                for (int i = currexecutor; i < size; i++)
                {
                    Enqueue(head->data);
                    Dequeue();
                }
                dead++;
                print();
            }
        }
    }
    void josephproblem(RenderWindow& window){}
    Node* getfront() {
        return head;
    }
    
};
void printwindow(Queue<int>& q1,int n,int k,RenderWindow& window) {
    SoundBuffer kill;
    Sound killer;
    kill.loadFromFile("2.mp3");
    killer.setBuffer(kill);
    killer.setVolume(100);
    Texture dead;
    Texture alive;
    dead.loadFromFile("dead.png");
    alive.loadFromFile("alive.png");
    float maxRadius = 400.0f;  // Set maximum radius for the circle
    float baseSpriteSize = 50.0f;  // Base size of each sprite
    float scaleFactor = min(2.0f, (maxRadius / n));
    float scaledSpriteSize = baseSpriteSize * scaleFactor;
    if (n>20)
    {
        scaledSpriteSize -= n+5;
    }
    Sprite sodead;
    sodead.setScale((scaledSpriteSize / dead.getSize().x) , (scaledSpriteSize / dead.getSize().y ));
    Sprite soalive;
    soalive.setScale(scaledSpriteSize / alive.getSize().x, scaledSpriteSize / alive.getSize().y);
    sodead.setTexture(dead);
    soalive.setTexture(alive);
    float centerx = (window.getSize().x)/2+200;
    float centery = (window.getSize().y)/2+200;
    float radius = maxRadius * 0.9f;
    if (n<20)
    {
        radius = maxRadius * 0.75f;
    }
    if (n<10)
    {
        radius = maxRadius * 0.7f;
    }
    float pi = 3.1415;
    for (int i = 0; i < n; i++)
    {
        if (q1.getfront()->data == 0) {
            sodead.setPosition((centerx + radius * cos(i * 2.0f * (pi) / n) - dead.getSize().x)+110,(centery + radius * sin(i * 2.0f * (pi) / n) - dead.getSize().y));
            window.draw(sodead);
        }
        else {
            soalive.setPosition(centerx + radius * cos(i * 2.0f * (pi) / n) - alive.getSize().x, centery + radius * sin(i * 2.0f * (pi) / n) - alive.getSize().y);
            window.draw(soalive);
        }
        q1.Enqueue(q1.getfront()->data);
        q1.Dequeue();
    }
    killer.play();
    sleep(seconds(1));
    window.display();
    sleep(seconds(0.4));
    window.clear();
}
void printwinner( RenderWindow& window,int x) {
    Texture alive;
    Font message;
    message.loadFromFile("1.ttf");
    Text text;
    text.setFont(message);
    text.setString("the winner is:" + to_string(x));
    text.setCharacterSize(50);
    text.setPosition(100, 100);
    alive.loadFromFile("winner.jpg");
    Sprite soalive;
    soalive.setScale(1, 0.9);
    soalive.setTexture(alive);
    float centerx = (window.getSize().x) / 2 + 200;
    float centery = (window.getSize().y) / 2 + 350+200;
    soalive.setPosition(centerx - alive.getSize().x, centery  - alive.getSize().y);
    window.draw(soalive);
    window.draw(text);
    window.display();
    sleep(seconds(1));
    window.clear();

}
void Queue<int>:: josephproblem(RenderWindow& window) {
    while (window.isOpen())
    {
        Event event;
        Music backgroundMusic;
        backgroundMusic.openFromFile("1.mp3");
        backgroundMusic.setLoop(true);
        backgroundMusic.setVolume(50);
        backgroundMusic.play();
        for (int i = 1; i < size; i++)
        {
            if (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
                    break;
                }
                if (Event::KeyPressed)
                {
                    if (event.key.code == Keyboard::Escape) {
                        window.close();
                        break;
                    }
                }
            }
            
            cout << "loop " << i << ":\n";
            kill();
            printwindow(*this,size,k,window);
        }

        Node* temp = head;
        while (temp->data == 0)
        {
            temp = temp->next;
        }
        cout << "THE SURVIVOR IS :" << temp->data;
        backgroundMusic.setLoop(false);
        Music winner;
        winner.openFromFile("3.mp3");
        winner.setLoop(true);
        winner.setVolume(20);
        winner.play();
        int x = temp->data;
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                {
                    window.close();
                    break;
                }
                if (Event::KeyPressed)
                {
                    if (event.key.code == Keyboard::Escape) {
                        window.close();
                        break;
                    }
                }
            }
            
            printwinner(window,x);
        }
    }

    
}

int main() {
    int n, k;
    cout << "ENTER n:";
    cin >> n;
    cout << "ENTER k:";
    cin >> k;
    Queue<int> s1(n, k);
    RenderWindow w(sf::VideoMode(900,900),"josephproblem",Style::Close|Style::Titlebar);
    w.setFramerateLimit(60);
    s1.josephproblem(w);
}