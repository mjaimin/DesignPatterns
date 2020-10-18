#include <iostream>
//Strategy : public
class CompressionStrategy {
    public:
        virtual void compressFiles() = 0;
};

class ZipCompressionStrategy : public CompressionStrategy {
    public:
        void compressFiles() {
            std::cout << "using ZIP approach" << std::endl;
        }
};

class RarCompressionStrategy : public CompressionStrategy {
    public:
        void compressFiles() {
            std::cout << "using RAR approach" << std::endl;
        }
};

class CompressionContext {
    private:
        CompressionStrategy* strategy;
        //this can be set at runtime by the application preferences
    public:
        void setCompressionStrategy(CompressionStrategy* strategy) {
            this->strategy = strategy;
        }

        //use the strategy
        void createArchive() {
            strategy->compressFiles();
        }
};


main(){
    CompressionContext* ctx = new CompressionContext();
    ctx->setCompressionStrategy(new ZipCompressionStrategy());
    ctx->createArchive();
}

