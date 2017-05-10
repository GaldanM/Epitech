#ifndef BOMBERMAN_ACharacter_H
# define BOMBERMAN_ACharacter_H

# include "Model.hh"
# include "Map.hh"


class ACharacter : public AObject
{
protected:
	float								_speed;
	int 								_score;
	int 								_nbBomb;
	int 								_range;
	gdl::Model							_model;
	gdl::Clock							_clock;
	Map 								*_map;
	int 								_keyPressed;
	bool								_dead;
	int									_up;
	int									_down;
	int									_left;
	int									_right;
	bool								_imIn;
	int 								_direction;
	bool								_inFlee;
	int									_run;
	int 								_idEnemy;
	glm::vec3 							_toGo;
	int 								_tacticIa;

public:
	ACharacter(const float, const float);
	virtual ~ACharacter();
	

	virtual void	update(const gdl::Clock&, gdl::Input&, Map *map) = 0;
	virtual void	draw(gdl::AShader&, const gdl::Clock&);

	void			gereAnim(int);
	int				round(float);
	void			forward(int, int, const glm::vec3&, bool, bool);

	int 			getScore() const;
	void			setScore(int);

	int 			getBomb() const;
	void			setBomb(int);
	
	int 			getRange() const;
	void			setRange(int);

	float 			getSpeed() const;
	void			setSpeed(float);


	const glm::vec3	getPosition() const;

	void    		playersConditions(AObject::Type current);
	
	bool			getDead() const;
	void			setDead();

	void			goUp(int);
	void			goDown(int);
	void			goRight(int);
	void			goLeft(int);


	
	int				getUp() const;
	int				getDown() const;
	int				getLeft() const;
	int				getRight() const;

	void			setUp(int);
	void			setDown(int);
	void			setLeft(int);
	void			setRight(int);

	void			setImIn(bool);
	bool			getImIn() const;

	void			setDirection(int);
	int 			getDirection() const;

	bool			getInFlee() const;
	void			setInFlee(bool);

	int				getRun() const;
	void			setRun(int);

	int 			getIdEnemy() const;
	void			setIdEnemy(int);

	const glm::vec3	getToGo() const;
	void			setToGo(const glm::vec3&);

	
	void 			setTacticIa(int tac);
	int 			getTacticIa() const;
};

#endif /* BOMBERMAN_ACharacter_H */