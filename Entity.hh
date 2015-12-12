#ifndef ENTITY_hh
#define ENTITY_hh

class Entity {
	private:
		
	public:
		virtual void update(){}
		virtual void render(){}
		virtual ~Entity(){}
		virtual bool colliding(int x, int y){(void)x;(void)y;return false;}
};

#endif
