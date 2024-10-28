//#include <iostream>
//#include <queue>
//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <cmath>  // for cos and sin
//
//using namespace std;
//
//int josephus(int N, int K, vector<int>& eliminationOrder) {
//    queue<int> circle;
//    for (int i = 1; i <= N; i++)
//        circle.push(i);
//
//    while (circle.size() > 1) {
//        for (int i = 0; i < K - 1; i++) {
//            circle.push(circle.front());
//            circle.pop();
//        }
//        eliminationOrder.push_back(circle.front());
//        circle.pop();
//    }
//    return circle.front();
//}
//
//int main() {
//    int N, K;
//    cout << "Enter the number of people (N): ";
//    cin >> N;
//    cout << "Enter the count step (K): ";
//    cin >> K;
//
//    vector<int> eliminationOrder;
//    int survivor = josephus(N, K, eliminationOrder);
//    cout << "The survivor is person: " << survivor << endl;
//
//    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Josephus Problem Visualization");
//    sf::Texture aliveTexture, deadTexture;
//    aliveTexture.loadFromFile("1.png");
//    deadTexture.loadFromFile("2.png");
//
//    sf::Music backgroundMusic;
//    backgroundMusic.openFromFile("1.ogg");
//    backgroundMusic.setLoop(true);
//    backgroundMusic.play();
//
//    sf::SoundBuffer swordSlashBuffer;
//    swordSlashBuffer.loadFromFile("1.wav");
//    sf::Sound swordSlashSound;
//    swordSlashSound.setBuffer(swordSlashBuffer);
//
//    // Determine the sprite size scaling factor based on N
//    float maxRadius = 400.0f;  // Set maximum radius for the circle
//    float baseSpriteSize = 50.0f;  // Base size of each sprite
//    float scaleFactor = min(2.0f, (maxRadius / N));
//    float scaledSpriteSize = baseSpriteSize * scaleFactor;
//
//    vector<sf::Sprite> peopleSprites(N);
//    vector<bool> eliminated(N, false);
//
//    // Create sprites for each person in the circle
//    for (int i = 0; i < N; i++) {
//        peopleSprites[i].setTexture(aliveTexture);
//        peopleSprites[i].setScale(scaledSpriteSize / aliveTexture.getSize().x, scaledSpriteSize / aliveTexture.getSize().y);
//
//        // Calculate the angle for each sprite based on its index
//        float angle = i * (2.0f * 3.1415 / N);  // Use radians for angle calculation
//        float radius = maxRadius * 0.9f;  // Adjust radius to ensure spacing (90% of maxRadius)
//
//        // Position the sprite at the calculated angle
//        peopleSprites[i].setPosition(
//            (window.getSize().x / 2) + radius * cos(angle),  // Center horizontally
//            (window.getSize().y / 2) + radius * sin(angle)   // Center vertically
//        );
//    }
//
//    int currentIndex = 0;
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//
//        for (int i = 0; i < N; i++) {
//            if (eliminated[i]) {
//                peopleSprites[i].setTexture(deadTexture);
//            }
//            window.draw(peopleSprites[i]);
//        }
//
//        window.display();
//
//        if (currentIndex < eliminationOrder.size()) {
//            int eliminatedPerson = eliminationOrder[currentIndex];
//            eliminated[eliminatedPerson - 1] = true;  // Mark person as eliminated
//
//            swordSlashSound.play();
//            sf::sleep(sf::seconds(1));  // Delay before next elimination
//            ++currentIndex;  // Move to the next person in the elimination order
//        }
//    }
//
//    return 0;
//}