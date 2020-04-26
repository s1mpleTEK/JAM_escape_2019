#ifndef MUSIC_H_
#define MUSIC_H_

#include <SFML/Audio.hpp>

class Music
{
    public :

    void addMusic(char const *path)
    {
        if (!music.openFromFile(path))
            return;
    };

    void loop(bool state)
    {
        music.setLoop(state);
    }

    void play(void)
    {
        music.play();
        music.setVolume(50);
    }

    void stop(void)
    {
        music.stop();
    }



    private:

    sf::Music music;
};

#endif /* !MUSIC_H_ */