#ifndef SCENENODE_H
#define SCENENODE_H
#include <SFML/Graphics.hpp>
#include <memory>

class Transform;

class SceneNode : public sf::Transformable, private sf::NonCopyable
{
    public:
        typedef std::unique_ptr<SceneNode> Ptr;

        SceneNode();
        virtual ~SceneNode();

        //Public Methods
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states, float interpolation);
        virtual void update(float dt);

        sf::Transform getWorldTransform() const;
        sf::Vector2f getWorldPosition() const;

        //Children
        void attachChild(Ptr child);
        Ptr detachChild(const SceneNode &node);

        //Public Fields
        std::vector<Ptr> mChildren;
        SceneNode* mParent;
        bool canControl = false;
    protected:
        virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states, float interpolation){};
        virtual void updateSelf(float dt){};

        virtual void drawChildren(sf::RenderTarget& target, sf::RenderStates states, float interpolation);
        virtual void updateChildren(float dt);
    private:
        bool drawChildrenFirst = true;

        sf::Transformable previousLocalTransform;

        sf::Transform getInterpolatedTransform(float interpolation);
        void updateWorldTransform();
};

#endif // SCENENODE_H
