#include <iostream>
#include <list>
#include <memory>

using namespace std;

class AudioCommand {
public:
    virtual void execute() = 0;
    virtual ~AudioCommand() {};
};

class PlayCommand : public AudioCommand {
public:
    PlayCommand(uint32_t time, uint8_t volume);
    void execute() override
    {
        fprintf(stderr, "play music %d %d\n", play_time_, volume_);
    }
private:
    uint32_t play_time_;
    uint8_t volume_;
};

PlayCommand::PlayCommand(uint32_t time, uint8_t volume):play_time_(time), volume_(volume)
{
    if (time == 0 || volume > 100) {
        throw invalid_argument("Invalid parameters");
    }
}

class StopCommand : public AudioCommand {
public:
    StopCommand() {}
    void execute() override
    {
        cout << "stop music" << endl;
    }
};

/* 命令执行者 */
class Invoker {
public:
    static Invoker& Instance()
    {
        static Invoker instance;
        return instance;
    }

    void executeCommand()
    {
        for (auto command : command_list_) {
            command->execute();
        }
    }
    
    void clearCommand()
    {
        command_list_.clear();
    }

    void addCommand(shared_ptr<AudioCommand> command)
    {
        command_list_.push_back(command);
    }
private:
    Invoker() {}
    ~Invoker() {}
    Invoker(const Invoker&) = delete;
    Invoker& operator=(const Invoker&) = delete;
    list<shared_ptr<AudioCommand>> command_list_;
};



int main()
{
    Invoker::Instance().addCommand(make_shared<PlayCommand>(10, 50));
    Invoker::Instance().addCommand(make_shared<PlayCommand>(2, 40));
    Invoker::Instance().addCommand(make_shared<StopCommand>());
    Invoker::Instance().addCommand(make_shared<PlayCommand>(1, 4));

    Invoker::Instance().executeCommand();
    return 0;
}