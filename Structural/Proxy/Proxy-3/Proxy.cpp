#include <iostream>
#include <string>

class Image //interface
{
    public:
        virtual void showImage() = 0;
};

class RealImage: public Image
{
    private:
        std::string m_fileName;
    public:
        RealImage(std::string strFileName)
        {
            this->m_fileName = strFileName;
        }
    public:
        void showImage()
        {
            std::cout << "Show Image:" << m_fileName << std::endl;
        }
};

class ProxyImage: public Image {
    private:
        RealImage* m_image;
        std::string m_fileName;

    public:
        ProxyImage(std::string strFileName): m_fileName(strFileName), m_image(NULL) {}
    public:
        void showImage()
        {
            if( m_image == NULL)
            {
                m_image = new RealImage(m_fileName);
            }
            m_image->showImage();
        }
};

int main()
{
    Image* img1 = new ProxyImage("Image***1");
    Image* img2 = new ProxyImage("Image***2");
    img1->showImage();
    img2->showImage();
}
